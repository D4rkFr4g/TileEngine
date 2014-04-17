#include "EventQueue.h"

/*-----------------------------------------------*/
EventQueue::EventQueue(void)
{
   eventQueue.reserve(16);
}
/*-----------------------------------------------*/
EventQueue::~EventQueue(void)
{
}
/*-----------------------------------------------*/
void EventQueue::queueEvent(Event* ev)
{
   eventQueue.push_back(*ev);
}
/*-----------------------------------------------*/
void EventQueue::updateEventQueue(void)
{
   int i;
   for( i = 0; i < eventQueue.size(); ++i ) 
      handleEvent( &eventQueue[i]);
   
   eventQueue.clear();
}
/*-----------------------------------------------*/
void EventQueue::handleEvent(Event* ev)
{

}