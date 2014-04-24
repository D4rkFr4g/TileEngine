#pragma once
#include <memory>
#include "fmod_studio.hpp"
#include "fmod_errors.h"
#include "EventListener.h"
#include "EventQueue.h"

class Audio : public EventListener
{
public:
   Audio();
   Audio(FMOD::System* fmodSystem, FMOD::ChannelGroup* channelMusic, FMOD::ChannelGroup* channelEffects);
   ~Audio(void);
   virtual void notify(Event* event) override;
   void registerListeners(EventQueue* eventQueue);

   // Variables
   FMOD_RESULT result;
   FMOD::System* fmodSystem;
   FMOD::ChannelGroup* channelMusic;
   FMOD::ChannelGroup* channelEffects;
   FMOD::Sound* bgMusic[1];
};

