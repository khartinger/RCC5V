//_____D1_class_Statemachine.cpp______________181002-240220_____
// The class Statemachine helps to build a state counter.
// It counts from 1 to stateMax (incl.) and waits
// "stateDelay" milliseconds for every state.
// Created by Karl Hartinger, October 02, 2018.
// Modified
// 2018-10-05 some set/get added
// 2018-10-19 stateMin, add() added
// 2020-01-19 getBeginMillis() added
// 2020-02-25 getStateMin() added
// 2020-03-03 add(..,..), diff() added
// 2020-04-05 add getBeginMillis()
// 2021-01-31 state: change int to int32_t
// 2021-04-11 add isDelayed(), delayed (ms)
// 2024-02-20 replace delay() by while(), add getDelayed()
// 2024-02-22 defines STATE_MINIMUM, STATE_NOW, STATE_NONE
// Released into the public domain.
#include "D1_class_Statemachine.h"

//**************************************************************
//     constructor & co
//**************************************************************

//_____constructor______________________________________________
Statemachine::Statemachine() { setup(); }

Statemachine::Statemachine(int32_t state_max, int32_t state_delay)
{
 setup();
 setStateMax(state_max);
 setStateDelay(state_delay);
 stateCounter=stateMin;
}

Statemachine::Statemachine(int32_t state_min, int32_t state_max, int32_t state_delay)
{
 setup();
 if(state_min>state_max) 
  { int32_t temp=state_min; state_min=state_max; state_max=temp; }
 stateMin=state_min;
 stateMax=state_max;
 setStateDelay(state_delay);
 stateCounter=stateMin;
}

//_____setup properties_________________________________________
void Statemachine::setup() {
 stateMin=STATE_ONE;
 stateMax=STATE_LAST;
 stateDelay=STATE_DELAY_DEFAULT;
 stateCounter=stateMin;
 millisBegin=millis();
 delayed=0;
}

//**************************************************************
//     set values
//**************************************************************

//_____set first state (=minimum), if <= state maximum__________
bool Statemachine::setStateMin(int32_t state_min)
{
 if(state_min<STATE_MINIMUM) return false;
 if(state_min<=stateMax){
  stateMin=state_min; 
  if(stateCounter<stateMin) stateCounter=stateMin;
  return true; 
 }
 return false;
}

//_____set last state (=maximum), if >= state minimum___________
bool Statemachine::setStateMax(int32_t state_max)
{
 if(state_max>=stateMin){
  stateMax=state_max; 
  if(stateCounter>stateMax) stateCounter=stateMax;
  return true; 
 }
 return false;
}

//_____set state delay (if >=0)_________________________________
bool Statemachine::setStateDelay(int32_t state_delay)
{
 if(state_delay>=0) { stateDelay=state_delay; return true; }
 return false;
}

//_____set state (convert to range stateMin...stateMax)_________
bool Statemachine::setState(int32_t new_state)
{
 int64_t numberAllStates=(int64_t)stateMax-stateMin+1;
 if(numberAllStates<=0) return false;
 //-----transform new_state to range stateMin...stateMax--------
 int64_t offset=((int64_t)new_state-stateMin)%numberAllStates;
 if(offset<0) offset+=numberAllStates;
 stateCounter=(int32_t)((int64_t)stateMin+offset);
 return true;
} 

//**************************************************************
//     get values
//**************************************************************

int32_t Statemachine::getStateMin()   { return stateMin; }
int32_t Statemachine::getStateMax()   { return stateMax; }
uint32_t Statemachine::getStateDelay() { return stateDelay; }
int32_t Statemachine::getState()      { return stateCounter; }
uint32_t Statemachine::getDuration() {return(millis()-millisBegin);}
uint32_t Statemachine::getBeginMillis(){ return millisBegin; }

//**************************************************************
//     working methods
//**************************************************************

//_____use this at the beginning of the loop-function___________
// returns the number of the actual state
int32_t Statemachine::loopBegin()
{
 millisBegin=millis();                 // get start "time"
 return stateCounter;
}

//_____use this at the end of the loop-function_________________
// increases state number and returns duration of last state
uint32_t Statemachine::loopEnd()
{
 stateCounter=this->add(1);
 uint32_t millisEnd=millis();
 uint32_t duration=millisEnd-millisBegin;
 //------wait a little bit if necessary-------------------------
 uint64_t elapsed=(uint64_t)duration+delayed;
 if(elapsed > stateDelay)
 {//-----state machine is delayed: dont wait, prepare next state
  uint64_t overdue=elapsed-stateDelay;
  uint64_t maxDelayed=100ULL*stateDelay;
  //.....limit for making up the delay: 100*stateDelay..........
  delayed=(overdue>maxDelayed) ? (uint32_t)maxDelayed : (uint32_t)overdue;
 } else
 {//-----wait a little until the next state can be started------
  while(millis()-millisEnd < stateDelay) yield();
  delayed=0;                      // just in time, not delayed
 }
 return duration;
}

//_____Add a number of states to actual state___________________
// return: the new state number
// Note: Method does NOT change the stateCounter!
int32_t Statemachine::add(int32_t numberOfStates)
{
 return add(stateCounter, numberOfStates);
}

//_____Add a number of states to given state____________________
// return: the new state number
// Note: Method does NOT change the stateCounter!
int32_t Statemachine::add(int32_t state, int32_t numberOfStates)
{
 int64_t numberAllStates=(int64_t)stateMax-stateMin+1;
 if(numberAllStates<=0) return stateCounter;
 if(numberOfStates==0) return state;
 //-----transform state to range stateMin...stateMax------------
 int64_t offset=((int64_t)state-stateMin)%numberAllStates;
 if(offset<0) offset+=numberAllStates;
 //-----transform numberOfStates to range 0...(Max-Min+1)-------
 int64_t steps=(int64_t)numberOfStates%numberAllStates;
 if(steps<0) steps+=numberAllStates;
 //-----add value to state--------------------------------------
 return (int32_t)((int64_t)stateMin+(offset+steps)%numberAllStates);
}

//_____return difference between stateCounter and old_state_____
// return difference as POSITIVE value e.g. states 11..17
// stateCounter=16, old_state=12: diff=16-12=4
// stateCounter=12, old_state=16: diff=12-16+(17-11+1)=3
// on error: return -1;
int32_t Statemachine::diff(int32_t oldState)
{
 int64_t numberAllStates=(int64_t)stateMax-stateMin+1;
 if(numberAllStates<=0) return -1;
 //-----transform oldState to range stateMin...stateMax---------
 int64_t oldOffset=((int64_t)oldState-stateMin)%numberAllStates;
 if(oldOffset<0) oldOffset+=numberAllStates;
 int64_t currentOffset=((int64_t)stateCounter-stateMin)%numberAllStates;
 if(currentOffset<0) currentOffset+=numberAllStates;
 return (int32_t)((currentOffset-oldOffset+numberAllStates)%numberAllStates);
}

//_____is start of this state delayed?__________________________
bool Statemachine::isDelayed() { 
 if(delayed==0) return false;
 return true;
}

//_____how long are the states delayed?_________________________
uint32_t Statemachine::getDelayed() { return delayed; }