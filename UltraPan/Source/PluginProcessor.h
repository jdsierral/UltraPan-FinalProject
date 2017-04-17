/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginParams.h"
#include "SpeakerSet.h"


//==============================================================================
/**
*/
class UltraPanAudioProcessor  : public AudioProcessor
//								, public OSCReceiver,
//public OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback>

{
public:
    //==============================================================================
    UltraPanAudioProcessor();
    ~UltraPanAudioProcessor();

    //==============================================================================
	void numChannelsChanged() override;
	#ifndef JucePlugin_PreferredChannelConfigurations
	bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
	#endif
	bool canAddBus(bool isInputBus) const override;
	bool canRemoveBus(bool isInputBus) const override;
	
    //==============================================================================
	
	void prepareToPlay (double sampleRate, int samplesPerBlock) override;
	void releaseResources() override;
    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

	//==============================================================================
	//==============================================================================
	//==============================================================================
	
	void clearGuiFlag() { guiFlag = false;}
	void setGuiFlag()	{ guiFlag = true;}
	bool getGuiFlag()	{ return guiFlag;}
	
	//==============================================================================
	
	
	void setSpeakerPos(int sp, Vector3D<float> newSpeakerPos);
	void setSpeakerPosX(int sp, float newPosX);
	void setSpeakerPosY(int sp, float newPosY);
	void setSpeakerPosZ(int sp, float newPosZ);
	void setBase(float newBase);
	
	//==============================================================================
	
	Vector3D<float> getSourcePos (int sc);
	Vector3D<float> getSpeakerPos (int sp);
	float getSpeakerPosX(int sp, float newPosX);
	float getSpeakerPosY(int sp, float newPosX);
	float getSpeakerPosZ(int sp, float newPosX);
	
	//==============================================================================
	
	AudioParameterCustomBool* bypass;
	AudioParameterCustomFloat* mainVol;
	AudioParameterCustomFloat* base;
	
	AudioParameterCustomFloat* pos1X;
	AudioParameterCustomFloat* pos1Y;
	AudioParameterCustomFloat* pos1Z;
	
	AudioParameterCustomFloat* pos2X;
	AudioParameterCustomFloat* pos2Y;
	AudioParameterCustomFloat* pos2Z;
	
private:
	bool guiFlag;
	float mainVolVal;
	
	//==============================================================================
	//==============================================================================
	
	OwnedArray<SpeakerSet> speakerSet;
	std::vector<AudioSampleBuffer> tempIn;
	
	OwnedArray<Spkr> speakerGroup;
	
	AudioSampleBuffer dlyBuffer;
	int rdPtr;
	int wtPtr;
	
		
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UltraPanAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
