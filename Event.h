#pragma once
#include <unordered_map>

class Event
{
public:
   // Constructors
   Event(void);
   ~Event(void);

   // Variables
   enum EventType
   {
      ET_COLLISION_START,
      ET_COLLISION_END,
      ET_COLLISION_PROJECTILE,
      ET_HEALTH_DOWN,
      ET_HEALTH_UP,
      ET_LEVEL_END
   };
   EventType type;
   std::unordered_map<std::string, std::string> strParams;
   std::unordered_map<std::string, float> numParams;
};