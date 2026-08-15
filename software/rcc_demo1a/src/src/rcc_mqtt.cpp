//_____rcc_mqtt.cpp______________________________khartinger_____

#include "rcc_mqtt.h"

extern strRcomp aRcomp[RCOMP_NUM];
extern strRcmd aRcmd[RCOMP_NUM];
extern String setRcmd(int iRcomp, int iCmdValue, String sReturn);
extern void showLine(int line_, String text_);

// extern const int PIN_BUTTON;

 //_______MQTT communication_____________________________________
 //SimpleMqtt client("..ssid..", "..password..","mqttservername");
 //SimpleMqtt client("Raspi11", "12345678","10.1.1.1", TOPIC_BASE);

 SimpleMqtt client{String(_SSID_), String(_PASS_),
                   String(_HOST_), String(TOPIC_BASE)};

//______________________________________________________________
bool   bUseWiFi=false;                      // no Wifi available
int    iConn=CON_UNKNOWN;                   // WiFi unknown
int    iConnOld=CON_UNKNOWN;                // WiFi unknown

#if _USE_WIFI_ == true
//_______MQTT: inspect all subscribed incoming messages_________
/**
 * @brief MQTT call back routine
 * 
 * @details Checks whether a received message matches the syntax 
 * TOPIC_BASE/get, TOPIC_BASE/set/TOPIC_SET, or TOPIC_SUB.
 * If so, the system triggers the generation of a response.
 * 
 * @note client.callback_() must be called!
 * 
 * @param topic 
 * @param payload 
 * @param length length of payload
 */
void callback(char* topic, byte* payload, unsigned int length)
{
 client.callback_(topic, payload, length);  // must be called!
}
#endif

//______________________________________________________________
/**
 * @brief setup WiFi, connect to WiFi and MQTT-server
 * 
 */
bool initRccWiFi(Screen154 &screen_) {
 bool bRet;
 String s1, s2;
 //------use WiFi and MQTT?-------------------------------------
 bUseWiFi=(_USE_WIFI_ ? true : false);
 //------Setup WiFi/MQTT client---------------------------------
 #if _USE_WIFI_ == true
  if(bUseWiFi) {
   //---------WiFi (wlan) data from eeprom?---------------------
   bRet=client.eepromBegin();
   if(DEBUG_99){
    if(bRet) Serial.println("EEPROM initial OK");
    else     Serial.println("EEPROM initial ERROR");
   }
   int iRet_=0;
   String sWlan=client.eepromReadMyData(iRet_);
   if(iRet_>0) {
    int i1 = sWlan.indexOf('|');
    int i2 = sWlan.indexOf('|', i1 + 1);
    if(i1>0 && i2>0) {
     client.setWlanData(sWlan.substring(0, i1),
      sWlan.substring(i1+1,i2) ,sWlan.substring(i2+1));
    }
   }
   //---------other WiFi settings-------------------------------
   client.setWiFiHostName(_ESP_NAME_);        // device name
   client.setLanguage(LANGUAGE);              // e=english,d=german
   client.setCallback(callback);              // mqtt receiver
   client.setTopicBaseDefault(TOPIC_BASE);    // topic base
   client.setWiFiWaitingTime(1000);           // set a short time (1s)
   client.setWiFiConnectingCounter(19);       // try 10s connecting
   s1="";
   for(int i=0; i<RCOMP_NUM; i++) {
    s1+=","+aRcomp[i].name;
    s1+=","+String(aRcomp[i].dcc);
   }
   client.setTopics(String(TOPIC_GET)+s1,String(TOPIC_SET)+s1,TOPIC_SUB,TOPIC_PUB);
   //client.setRetainedIndex("get",3,true);
   client.begin();                            // setup objects
   //-----Show connecting procedure-----------------------------
   s1="WiFi "+client.getsSSID()+" connecting...";
   s1=s1.substring(0,SCREEN_LINE_LEN);        // max. 21 character
   screen_.screen15(2,s1);                    // line 2: begin connect
   screen_.screen15(4,"Button: skip WiFi -->");   // line4: 
   if(DEBUG_99) Serial.print("setup(): "+s1+String("\n"));
   client.connectingWiFiBegin();              // begin connecting
   int iUseWiFi=30;
   //.....waiting for WiFi connection............................
   do {
    if(digitalRead(PIN_BUTTON)==0) { iUseWiFi=0; break; }
    bRet=client.connectingWiFi();             // try to connect
    screen_.screen15Dot(3);                   // line 3: waiting dot
    iUseWiFi--;
    if(DEBUG_99) Serial.println("  Waiting for WiFi: "+String(iUseWiFi));
   } while(!bRet && iUseWiFi>0);
   //.....END OF waiting for WiFi connection.....................
   if(iUseWiFi>0) {
    if(DEBUG_99) Serial.println("setup(): FOUND WiFi " + client.getsSSID());
    //----WiFi ok (no timeout)-----------------------------------
    iConn=CON_WIFI_OK;                        // WiFi OK
    bUseWiFi=true;                            // use WiFi
    client.doLoop();                          // mqtt loop
    s2=client.getsTopicBase();                // get topic base
    int iMqttReady=6;                         // try max. 3 secs
    while (!client.isMQTTConnected() && !client.isMQTTConnectedNew() && iMqttReady>0)
    {
     iMqttReady--;
     if(DEBUG_99) Serial.println("  Waiting for MQTT: "+String(iMqttReady));
     delay(500);
     client.doLoop();                          // mqtt loop
    };
    if(iMqttReady>0)
    {
     //----WiFi and MQTT OK: publish start info-------------------
     iConn=CON_MQTT_OK;                      // MQTT OK
     //client.bAllowMQTTStartInfo(false);     //NO mqtt (re)start info
     if(DEBUG_99) Serial.println("setup(): Connected to MQTT-broker: "+s2);
     String s3="{\"topicbase\":\""+s2+"\",\"signal\":"+client.getsSignal()+"}";
     client.publish_P("rcc/start/mqtt",s3.c_str(),false);
    }
    else
    {
     iConn=CON_NO_MQTT;                      // WiFi yes, MQTT no
    }
   } // END OF if(iUseWiFi>0)
   else 
   { //----WiFi timeout-----------------------------------------
    if(DEBUG_99) Serial.println("setup(): WiFi " + client.getsSSID() + "NOT FOUND!");
    iConn=CON_NO_WIFI;                        // NO WiFi
    bUseWiFi=false;                           // don´t use WiFi
    s2=T_NO_MQTT;                             // No control via MQTT
    s2=s2.substring(0,SCREEN_LINE_LEN);       // max. 21 character
   } // END OF WiFi timeout
   s1="WiFi "+ sConn[iConn]+ " " + client.getsSSID();
   showLine(2, s1);
   showLine(3, s2);
  }
  if(DEBUG_99) Serial.println("setup(): IP-Adresse: " + WiFi.localIP().toString());
  if(DEBUG_99) Serial.println("setup(): Hostname nach Verbindung: " + String(WiFi.getHostname()));
  bRet=true;
 #else
  //------Dont use WiFi anyway-----------------------------------
  iConn=CON_NO_WIFI;                        // NO WiFi
  s1=T_NO_MQTT;
  s1=s1.substring(0,SCREEN_LINE_LEN);       // max. 21 character
  showLine(2, s1);
  showLine(3, "");
  bRet=false;
 #endif
 return bRet;
}

// *************************************************************
// Control functions for WLAN data
// *************************************************************
#if _USE_WIFI_ == true

/*
 //_______MQTT communication_____________________________________
 //SimpleMqtt client("..ssid..", "..password..","mqttservername");
 //SimpleMqtt client("Raspi11", "12345678","10.1.1.1", TOPIC_BASE);

 SimpleMqtt client{String(_SSID_), String(_PASS_),
                   String(_HOST_), String(TOPIC_BASE)};
*/

//_______Check IP-Address_______________________________________
/**
 * Checks whether a string contains a valid IPv4 address.
 *
 * @param ip IP address string
 * @return true if valid
 */
bool isValidIPv4(const String &ip) {
  int parts = 0;
  int last = 0;
  for (int i = 0; i <= ip.length(); i++) {
    if (i == ip.length() || ip[i] == '.') {
      if (i == last) return false;  // leerer Block
      int num = 0;
      for (int j = last; j < i; j++) {
        if (!isDigit(ip[j])) return false;
        num = num * 10 + (ip[j] - '0');
        if (num > 255) return false;
      }
      parts++;
      last = i + 1;
    }
  }
  return parts == 4;
}

//_______check WLAN input string________________________________
/**
 * @brief Validates a WLAN configuration string.
 *
 * Checks whether the specified string is valid for use as a WLAN
 * configuration parameter.
 *
 * @param s String to validate (ssid|password|ip)
 * or ssid||ip if password is empty.
 * @return true if the string is valid, otherwise false.
 */
bool validateWlanString(const String &s) {
  // ----check for exactly 2x | --------------------------------
  int i1 = s.indexOf('|');
  if (i1 < 0) return false;
  int i2 = s.indexOf('|', i1 + 1);
  if (i2 < 0) return false;
  // kein drittes '|'
  if (s.indexOf('|', i2 + 1) >= 0) return false;
  // ----SSID cannot be empty-----------------------------------
  if (i1 == 0) return false;                // ssid empty
  // ----If the password cannot be blank: enable the next line--
  // if (i2 == i1 + 1) return false;        // password empty
  // ip cannot be empty-----------------------------------------
  if (i2 == s.length() - 1) return false;   // ip empty
  // ----Check whether “ip” is a valid value--------------------
  String ip = s.substring(i2 + 1);
  if (!isValidIPv4(ip)) return false;
  return true;
}

#endif

// *************************************************************
// MQTT Functions
// *************************************************************

#if _USE_WIFI_ == true


//_______Answer get requests____________________________________
/**
 * @brief Generates a response (string) to a GET request
 * 
 * @details The generated string is automatically sent as a
 * payload to the reply (answer) topic. 
 * The reply topic is the same as the get topic, 
 * except that "../ret/payload" is used instead of "../get".
 * 
 * For the topics "help", "version" and "ip" a response is 
 * automatically generated, which can also be expanded 
 * (generated string must start with "+") or overwritten.
 * @param sPayload The payload of the GET message, whose topic
 * must be included in the constant TOPIC_GET.
 * @return Payload for the response message (as String)
 */
String simpleGet(String sPayload)
{
 bool byName=true;
 String p1=String("");                      // JSON string
 String sKey=String("");                    // key help string
 String sVal=String("");                    // value help string
 sPayload.toLowerCase();                    // for easy compare
 //-------------------------------------------------------------
  if(sPayload=="help" || sPayload=="?") {
  p1 ="+MQTT: ../set/w1 -m 1|g|G OR -m 0|A|a|B|b (set by name)\r\n";
  p1+="      ../set/11 -m 1|g|G OR -m 0|A|a|B|b (set by dcc address)\r\n";
  p1+="      ../get -m byname|bydcc (values of all components)\r\n";
  return p1;
 }
 //-------------------------------------------------------------
  if(sPayload=="version") {
   addJson(p1, "version", VERSION_99);
   return p1;
 }
 //-------------------------------------------------------------
 if(sPayload=="mac") {
  addJson(p1, "mac", client.getsMac());
  addJson(p1, "hostname", client.getWiFiHostName());
  return p1;
 }
 //-------------------------------------------------------------
 if(sPayload=="ip") {
  addJson(p1, "ip", client.getsLocalIP());
  return p1;
 }
 //-------------------------------------------------------------
 if(sPayload=="signal") {
  addJson(p1, "signal", client.getsSignal());
  return p1;
 }
 //-------------------------------------------------------------
 if(sPayload=="topicbase") {
  addJson(p1, "topicbase", client.getsTopicBase());
  return p1;
 }
 //-------------------------------------------------------------
 if(sPayload=="eeprom") {
  //..........EEPROM read TopicBase.............................
  int iResult;
  sVal=client.eepromReadTopicBase(iResult);
  if(iResult<0) {
   if(iResult==-2) sVal="(no topic base)";
   else sVal=String("Error_#")+String(iResult);
  }
  addJson(p1, "topicbase", sVal);
  //..........EEPROM read MyData................................
  sVal=client.eepromReadMyData(iResult);
  if(sVal=="") sVal="(no data)";
  addJson(p1, "mydata", sVal);
  return p1;
 }
 //-------------------------------------------------------------
 //------is it a get command for all railroad components?--------
 if(sPayload=="byname" || sPayload=="bydcc" || sPayload=="status")
 {
  if(sPayload=="status") byName=false;
  for(int i=0; i<RCOMP_NUM; i++) { // ...for all components.....
   //.........get key...........................................
   if(sPayload=="byname") sKey= aRcomp[i].name;
   else sKey = String(aRcomp[i].dcc);
   //.........get value.for a component.........................
   sVal=getValueForComp(aRcomp[i], aRcmd[i], byName);
   addJson(p1, sKey, sVal);
  } // END OF for all components................................
  return p1;
 } // END OF if(sPayload=="byname"...

//-------------------------------------------------------------
 //------is it a get command for ONE railroad component by dcc or name?
 for(int i=0; i<RCOMP_NUM; i++) { // ...for all components.....
  p1="";
  sKey="";
  String s1=String(aRcomp[i].name);
  s1.toLowerCase();
  if(sPayload==s1) sKey=s1;
  s1=String(aRcomp[i].dcc);
  if(sPayload==s1) {sKey=s1; byName=false;}
  //..........For a valid GET request: find value...............
  if(sKey.length()>0) 
  {
   //.........get value.for a component.........................
   sVal=getValueForComp(aRcomp[i], aRcmd[i], byName);
   addJson(p1, sKey, sVal);
   return p1;
  }
 } // END OF for all components.................................
 //-------------------------------------------------------------
 addJson(p1, "error", "wrong get command");
 return p1;                                 // wrong Get command
}

//_______Execute set requests___________________________________
/**
 * @brief Processes SET request and generates a response
 * 
 * @details The generated string is automatically sent as a
 * payload to the reply (answer) topic. 
 * The reply topic is the same as the set topic, 
 * except that "../ret/xx" is used instead of "../set/xx".
 * 
 * @param sTopic The last part of the SET request after
 * "../set/" i.e., the entry from TOPIC_SET that is to 
 * be modified.
 * @param sPayload The new value to which the SET value 
 * should be set.
 * @return Payload for the response message (as String)
 */
String simpleSet(String sTopic, String sPayload)
{
 String p1=String("");                      // help string
 String sPayload0=sPayload;                 // original
 sTopic.toLowerCase();
 sPayload.toLowerCase();                    // for easy compare
 //-------------------------------------------------------------
 if(sTopic=="topicbase") {                  // new topic base?
  client.changeTopicBase(sPayload);         // change base
  addJson(p1, "topicbase", client.getsTopicBase());
//  p1="{\"topicbase\":\"";                   // start json
//  p1+=client.getsTopicBase();               // read new base
//  p1+="\"}";                                // end json
  showLine(3, client.getsTopicBase());      // show on display
  return p1;                                // return new base
 }
 //-------------------------------------------------------------
 if(sTopic=="wlan") {                       // erase eeprom?
  //----------check syntax sPayload0: ip|ssid|password-----------
  if(validateWlanString(sPayload0)) {
   int iRet_=client.eepromWriteMyData(sPayload0);
   if(iRet_>0) {
    int iRet2=0;
    String s1=client.eepromReadMyData(iRet2);
    if(iRet2<0) s1="EEPROM READ Error "+ String(iRet2);
    addJson(p1, "wlan", s1);
   } else {
    addJson(p1, "wlan", "EEPROM WRITE Error "+ String(iRet_));
   }
  } else {
   addJson(p1, "wlan", "syntax: ssid|password|IP or ssid||IP");
  }
  return p1;                                // return result
 }
 //-------------------------------------------------------------
 if(sTopic=="eeprom0") {                    // erase eeprom?
  if(sPayload=="?") {
   addJson(p1, "erase", "1=topicBase|2=myData|3=all");
   return p1;                               // return erase info
  }
  String sKey="my_data";
  String sVal="";
  p1="";
  if(sPayload=="2" || sPayload=="3" || sPayload=="all")
  {
   if(!client.eepromEraseMyData()) sVal+="NOT ";
   sVal+="deleted";                           // return answer 1
  }
  addJson(p1,sKey, sVal);
  if(sPayload=="1" || sPayload=="3" || sPayload=="all")
  {
   sKey="topicbase";
   sVal="";
   if(!client.eepromEraseTopicBase()) sVal+="NOT ";
   sVal+="deleted";                           // return answer 2
  }
  addJson(p1,sKey, sVal);
  if(p1=="") addJson(p1, "EEPROM", "Wrong payload");
  return p1;
 }
 //-------------------------------------------------------------

 //------is it a set command for a railroad component?-----------
 for(int i=0; i<RCOMP_NUM; i++)
 {
  p1="";
  String s1=String(aRcomp[i].name);
  s1.toLowerCase();
  if(sTopic==String(aRcomp[i].dcc) || sTopic==s1) {
   int iCmdValue=-1;
   //...........................................................
   if(aRcomp[i].type==RC_TYPE_TO || aRcomp[i].type==RC_TYPE_TX 
     || aRcomp[i].type==RC_TYPE_T3)
   { //.......for turnout commands..............................
    if(sPayload=="0" ||  sPayload=="a" || sPayload=="b") iCmdValue=0;
    if(sPayload=="1" || sPayload=="g") iCmdValue=1;
   } else 
   {
     //***Insert additional SET commands for non-turnouts here**
     //.......for all other command types.......................
    if(sPayload=="0") iCmdValue=0;
    if(sPayload=="1") iCmdValue=1;
   }
   addJson(p1, String(aRcomp[i].dcc), setRcmd(i, iCmdValue, sPayload));
   return p1;
  } // END OF if: set command for a railroad component
 } // END OF for-loop
 //-------------------------------------------------------------
 return String("");                         // wrong set command
}

//_______Execute sub requests___________________________________
/**
 * @brief Executes sub requests
 * 
 * @param sTopic A topic listed in the constant TOPIC_SUB
 * @param sPayload payload string for the topic
 * @return This function generates no automatic answer
 */
void simpleSub(String sTopic, String sPayload)
{
 //-------------------------------------------------------------
}

//______________________________________________________________
/**
 * @brief Processes SET request and generates a response
 * 
 * @details The generated string is automatically sent as a
 */
void loopMqtt(String &sSerial) {
 if(bUseWiFi) {
  //.....process mqtt actions...................................
  client.doLoop();                          // mqtt loop
  //=====(4) do, depending on the network access, ...===========
  if(client.isWiFiConnectedNew())    iConn=CON_WIFI_OK;// "WiFi OK   ";
  if(client.isMQTTConnectedNew())    iConn=CON_MQTT_OK;// "MQTT OK   ";
  if(client.isMQTTDisconnectedNew()) iConn=CON_NO_MQTT;// "-No MQTT--";
  if(client.isWiFiDisconnectedNew()) iConn=CON_NO_WIFI;// "-No WiFi--";
 } else {
  iConn=CON_WIFI_NOT_USED;                  // "unused WiFi"
 }
 //------show WLAN-/MQTT-connection status----------------------
 if(iConn!=iConnOld) {
  iConnOld=iConn;
  sSerial+=" | "+sConn[iConn];
  showLine(2,sConn[iConn]+" "+client.getsSSID());
 }
}

#endif


// _____________________________________________________________
/**
 * @brief Get the Value For Component object
 * 
 * @param Rcomp_ 
 * @param Rcmd_ 
 * @param byName 
 * @return String 
 */
String getValueForComp(strRcomp Rcomp_, strRcmd Rcmd_, bool byName) {
  if(Rcomp_.type==RC_TYPE_T3) {
  switch(Rcmd_.inValue) {
   case 0:  return byName ? T_STRAIGHT : T1_STRAIGHT; // BA=00
   case 1:  return byName ? T_CURVED : T1_CURVED;   // BA=01
   case 2:  return byName ? T_STRAIGHT : T1_STRAIGHT; // BA=10
   case 3:  return byName ? T_UNDEF1 : T1_UNDEF1;   // BA=11
   default: return byName ? T_UNKNOWN : T1_UNKNOWN; // ?? impossible
  }
 }
 if(Rcomp_.type==RC_TYPE_TO || Rcomp_.type==RC_TYPE_TX) {
  switch(Rcmd_.inValue) {
   case 0:  return byName ? T_UNDEF0 : T1_UNDEF0;   // BA=00
   case 1:  return byName ? T_STRAIGHT : T1_STRAIGHT; // BA=01
   case 2:  return byName ? T_CURVED : T1_CURVED;   // BA=10
   case 3:  return byName ? T_UNDEF1 : T1_UNDEF1;   // BA=11
   default: return byName ? T_UNKNOWN : T1_UNKNOWN; // ?? impossible
  }
 }
 if(Rcomp_.type==RC_TYPE_DT) { // discon track (fahrstrom)
  if(Rcmd_.inValue) return byName ? T_ON : T1_ON;
  else return byName ? T_OFF : T1_OFF;
 }
 if(Rcomp_.type==RC_TYPE_DD) { // double pole, double throw (2x UM)
  if(Rcmd_.inValue) return T1_DPDT_1_NO;
  else return T1_DPDT_0_NC;
 }
 if(Rcomp_.type==RC_TYPE_UC) {
  if(Rcmd_.inValue) return byName ? T_ON : T1_ON;
  else return byName ? T_OFF : T1_OFF;
 }
 if(Rcomp_.type==RC_TYPE_BL) {
  // Rcmd_.inValue ? return T1_ON : return T1_OFF;
  if(Rcmd_.iCmd==CMD_BLINK) return T1_ON;
  else return T1_OFF;
 }
 return byName ? T_UNKNOWN : T1_UNKNOWN;
}

// *************************************************************
// JSON Functions
// *************************************************************

// _____________________________________________________________
/**
 * @brief Adds a key-value pair to a JSON string
 * 
 * @param sJson: JSON string to be extended
 * @param sKey: Key as String
 * @param sValue: Value as String
 */
void addJson(String &sJson, const String &sKey, const String &sValue)
{
  //----------The key must not be empty-------------------------
  if(sKey.length()<1) return;
  // ---------Empty JSON string---------------------------------
  if (sJson.length()<1) { sJson = "{";  }
  else
  {
    // -------Remove closing brace------------------------------
    if (sJson.endsWith("}")) sJson.remove(sJson.length() - 1);
    // -------Add comma if JSON already contains elements-------
    if (sJson != "{") sJson += ",";
  }
  sJson += "\"";
  sJson += jsonEscape(sKey);
  sJson += "\":\"";
  sJson += jsonEscape(sValue);
  sJson += "\"}";       // close JSON object
}

// _____________________________________________________________
/**
 * @brief Replaces JSON escape sequences
 * 
 * @param  string with special characters
 * @return valid JSON string
 */
String jsonEscape(const String &s)
{
  String result;
  for (size_t i = 0; i < s.length(); i++)
  {
    char c = s[i];
    switch (c)
    {
      case '\"': result += "\\\""; break;
      case '\\': result += "\\\\"; break;
      case '\n': result += "\\n";  break;
      case '\r': result += "\\r";  break;
      case '\t': result += "\\t";  break;
      default:   result += c;      break;
    }
  }
  return result;
}
