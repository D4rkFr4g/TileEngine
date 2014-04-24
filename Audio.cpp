#include "Audio.h"

using namespace FMOD;

/*-----------------------------------------------*/
Audio::Audio()
{
}
/*-----------------------------------------------*/
Audio::Audio(System* fmodSystem, ChannelGroup* channelMusic, ChannelGroup* channelEffects, EventQueue* eventQueue)
{
   this->fmodSystem = fmodSystem;
   this->channelMusic = channelMusic;
   this->channelEffects = channelEffects;

   result = fmodSystem->createSound("Audio/bgmusic.mp3", FMOD_DEFAULT, 0, &bgMusic[0]);
   //registerListeners(eventQueue);
}
/*-----------------------------------------------*/
Audio::~Audio(void)
{
}
/*-----------------------------------------------*/
void Audio::notify(Event* event)
{
   // Do stuff
   //float x = (*event).numParams["level"];
   if (event->type == Event::ET_LEVEL_BEGIN)// && *event; //->numParams.find("level")->second == 0)
   {
      Channel* channel;
      fmodSystem->playSound(bgMusic[0], channelMusic, false, &channel);
   }
}
/*-----------------------------------------------*/
void Audio::registerListeners(EventQueue* eventQueue)
{
   //EventListener eL = &this;
   eventQueue->addEventListener(Event::ET_LEVEL_BEGIN, (EventListener*)this);
}
/*-----------------------------------------------*/