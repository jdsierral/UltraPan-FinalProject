/*
  ==============================================================================

    SpeakerSet.h
    Created: 26 Nov 2016 3:15:12pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef SPEAKERSET_H_INCLUDED
#define SPEAKERSET_H_INCLUDED

#include "Dsp.h"
#include "../JuceLibraryCode/JuceHeader.h"

struct Speaker{
	void init(int SR) {
		dsp.buildUserInterface(&params);
		dsp.init(SR);
	}
	
	void compute() {
		int bufSize = buffer.getNumSamples();
		float** data = buffer.getArrayOfWritePointers();
		dsp.compute(bufSize, data, data);
	}
	
	Dsp dsp;
	MapUI params;
	Vector3D<float> pos;
	AudioSampleBuffer buffer;
	String name;
	
	/* 
	 Params
	 
	/Sp/delay
	/Sp/gain
	*/

};

class SpeakerSet{
	
public:
	SpeakerSet();
	~SpeakerSet();
	
	//=================================================================
	
	void init(int sampleRate);
	
	//=================================================================
	
	void setNumSpeakers(int newNumSpeakers);
	
	void setBufferSize(int bufSize);
	
	//=================================================================
	
	void setSourcePos(Vector3D<float> newSourcePos);
	void setSourcePosX(float newPosX);
	void setSourcePosY(float newPosY);
	void setSourcePosZ(float newPosZ);
	
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
	
	
	//=================================================================
	
	void compute(AudioSampleBuffer& inBuffer, AudioSampleBuffer& outBuffer);
	
	//=================================================================
	
private:
	
	void updateAllSpeakers();
	void updateSpeaker(int numSpeaker);
	void checkMinDistance();
	void printParam(int sp);
	
	//=================================================================
	
	int totalNumSpeakers;
	
	Vector3D<float>	sourcePos;
	OwnedArray<Speaker> speakers;
	
	std::vector<float> test = {1, 2, 3, 4, 5};
	float base;
	float scale; // maybe it wont be needed;
	float SR;
	
	float minDist;
	const float c = 340.f;//m/s
	
	//	fmOsc.init(sampleRate);
	//	fmOsc.buildUserInterface(&oscParams);
	//	fmOsc.compute(bufSize, NULL, audioBuf);
};

#endif  // SPEAKERSET_H_INCLUDED
