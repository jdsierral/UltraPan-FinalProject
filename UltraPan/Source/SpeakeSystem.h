/*
  ==============================================================================

    SpeakeSystem.h
    Created: 15 Nov 2016 7:46:01pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef SPEAKESYSTEM_H_INCLUDED
#define SPEAKESYSTEM_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class SpeakerSystem
{
public:
	SpeakerSystem(int numSpeakers);
	~SpeakerSystem();
	
	void setSpeakerPos(int numSpeaker, Vector3D<float> speakerPos);
	Vector3D<float> getSpeakerPos(int numSpeaker);
	
	float getGain(int numSpeaker);
	
	void setSourcePos(Vector3D<float> newPos);
	void setSourcePosX(float newXPos);
	void setSourcePosY(float newYPos);
	void setSourcePosZ(float newZpos);
	
private:
	void updateGains();
	float computeGain(Vector3D<float> sourcePos, Vector3D<float> speakerPos);
	
	int numSpkrs;
	std::vector<Vector3D<float>> speaker;
	std::vector<float> gain;
	Vector3D<float> pos;
	
	const float base = M_E;
	
};
#endif  // SPEAKESYSTEM_H_INCLUDED
