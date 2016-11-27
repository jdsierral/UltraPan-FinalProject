/*
  ==============================================================================

    SpeakerSet.h
    Created: 24 Nov 2016 4:57:14am
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef SPEAKERSET_H_INCLUDED
#define SPEAKERSET_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "delay.h"


class SpeakerSet {
public:
	
	SpeakerSet();
	~SpeakerSet();
	
//=================================================================

	void initilize();
	
//=================================================================
	
	void setNumSpeakers(int newNumSpeakers);

//=================================================================
	
	void setSourcePosition(Vector3D<float> newSourcePos);
	void setSourceXPosition(float newSourceXPos);
	void setSourceYPosition(float newSourceYPos);
	void setSourceZPosition(float newSourceZPos);
	void setSpeakerPos(int numSpeaker, Vector3D<float> newSpeakerPos);
	void setBase (float newBase);
	void setScale (float newScale);
	
//=================================================================
	
	Vector3D<float> getSourcePosition();
	Vector3D<float> getSpeakerPos(int numSpeaker);
	float getSpeakerGain(int numSpeaker);
	float getBase();
	float getScale();
	
	
//=================================================================
	
private:
	
	void updateAllGains();
	void updateSpeakerGain(int numSpeaker);

//=================================================================
	
	OwnedArray<Vector3D<float>> speakerPos;
	Vector3D<float>	sourcePos;
	Array<float> gain;
	int totalNumSpeakers;
	
	OwnedArray<Delay> speaker;
	OwnedArray<MapUI> speakerParams;
	
	Array<Delay> test;
	
	
//	fmOsc.init(sampleRate);
//	fmOsc.buildUserInterface(&oscParams);
	
//	fmOsc.compute(bufSize, NULL, audioBuf);

	
	float base;
	float scale;
	
	float SR = 44100;
	
};



#endif  // SPEAKERSET_H_INCLUDED
