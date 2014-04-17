#pragma once
#include <vector>
#include <map>
#include <functional>
#include "Event.h"

class EventQueue
{
public:
   // Constructors
   EventQueue(void);
   ~EventQueue(void);

   // Functions
   void queueEvent(Event*);
   void updateEventQueue(void);
   void handleEvent(Event*);
   void addListener(Event::EventType, std::function<void(Event*)> callback);

private:
   // Variables
   std::vector<Event> eventQueue;
   std::map<int, std::vector<std::function<void(Event*)>>> listeners;
};
