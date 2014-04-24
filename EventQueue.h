#pragma once
#include <vector>
#include <unordered_map>
#include <functional>
#include <algorithm>
#include "Event.h"
#include "EventListener.h"


class EventQueue
{
public:
   // Constructors
   EventQueue(void);
   ~EventQueue(void);

   // Functions
   void queueEvent(Event*);
   void updateEventQueue(void);
   void notifyListeners(Event*);
   void addEventListener(Event::EventType, EventListener* listener);
   void removeEventListener(EventListener* listener);

private:
   // Variables
   std::vector<Event*> eventQueue;
   std::unordered_map<Event::EventType, std::vector<EventListener*>> listeners;
};

