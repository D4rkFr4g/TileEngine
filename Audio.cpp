#include "Audio.h"
#include <iostream>

using namespace FMOD;

/*-----------------------------------------------*/
Audio::Audio()
{
}
/*-----------------------------------------------*/
Audio::Audio(System* fmodSystem, ChannelGroup* channelMusic, ChannelGroup* channelEffects)
{
   this->fmodSystem = fmodSystem;
   this->channelMusic = channelMusic;
   this->channelEffects = channelEffects;

   result = fmodSystem->createSound("Audio/bgmusic.mp3", FMOD_DEFAULT, 0, &bgMusic[0]);
}
/*-----------------------------------------------*/
Audio::~Audio(void)
{
}
/*-----------------------------------------------*/
void Audio::notify(Event* event)
{
   // Do stuff
   if (event->type == Event::ET_LEVEL_BEGIN && event->numParams.find("level")->second == 0)
   {
      Channel* channel;
      fmodSystem->playSound(bgMusic[0], channelMusic, false, &channel);
   }
}
/*-----------------------------------------------*/
void Audio::registerListeners(EventQueue* eventQueue)
{
   eventQueue->addEventListener(Event::ET_LEVEL_BEGIN, this);
}
/*-----------------------------------------------*/