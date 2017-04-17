/*
  ==============================================================================

    Speaker.h
    Created: 18 Feb 2017 2:41:01am
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef SPEAKER_H_INCLUDED
#define SPEAKER_H_INCLUDED

class Spkr {
private:
	float gain;
	int smplDly;
	float fracDly;
	
	AudioSampleBuffer&  buf;
	Vector3D<float> pos;
	String name;
public:
	
	float compute(int rdPtr);
	
	
	void setSpeakerPos(int sp, Vector3D<float> newPos);
	void setSpeakerPosX(int sp, float newPosX);
	void setSpeakerPosY(int sp, float newPosY);
	void setSpeakerPosZ(int sp, float newPosZ);
	
	void setBase (float newBase);
	void setScale (float newScale);
	
	//=================================================================
	
	Vector3D<float> getSourcePosition();
	Vector3D<float> getSpeakerPos(int numSpeaker);
	float getSpeakerGain(int numSpeaker);
	float getSpeakerDelay(int numSpeaker);
	String getSpeakerName(int numSpeaker);
	float getBase();
	float getScale();
	
};



#endif  // SPEAKER_H_INCLUDED
