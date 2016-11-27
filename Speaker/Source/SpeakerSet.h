/*
  ==============================================================================

    SpeakerSet.h
    Created: 26 Nov 2016 12:38:32am
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
		
		int numParams = params.getParamsCount();
		for (int i = 0; i < numParams; i++) {
			std::cout<<params.getParamAdress(i)<<std::endl;
		}
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
};

class SpeakerSet{
	
public:
	SpeakerSet();
	~SpeakerSet();
	
	//=================================================================
	
	void init();
	
	//=================================================================
	
	void setNumSpeakers(int newNumSpeakers);
	
	void setBufferSize(int bufSize);
	
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
	float getSpeakerDelay(int numSpeaker);
	float getBase();
	float getScale();
	
	
	//=================================================================
	
	void compute(AudioSampleBuffer& inBuffer, AudioSampleBuffer& outBuffer);
	
	//=================================================================
	
private:
	
	void updateAllGains();
	void updateSpeakerGain(int numSpeaker);
	
	//=================================================================
	
	int totalNumSpeakers;

	Vector3D<float>	sourcePos;
	OwnedArray<Speaker> speakers;
	
	float base;
	float scale;
	float SR = 44100;
	
	//	fmOsc.init(sampleRate);
	//	fmOsc.buildUserInterface(&oscParams);
	//	fmOsc.compute(bufSize, NULL, audioBuf);
};



#endif  // SPEAKERSET_H_INCLUDED
