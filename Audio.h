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
   Audio(FMOD::System* fmodSystem, FMOD::ChannelGroup* channelMusic, FMOD::ChannelGroup* channelEffects, EventQueue* eventQueue);
   ~Audio(void);
   virtual void notify(Event* event) override;

   // Variables
   FMOD_RESULT result;
   FMOD::System* fmodSystem;
   FMOD::ChannelGroup* channelMusic;
   FMOD::ChannelGroup* channelEffects;
   FMOD::Sound* bgMusic[1];

private:
   void registerListeners(EventQueue* eventQueue);
};

