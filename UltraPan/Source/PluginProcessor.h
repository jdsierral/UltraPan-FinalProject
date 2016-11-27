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
{
public:
    //==============================================================================
    UltraPanAudioProcessor();
    ~UltraPanAudioProcessor();

    //==============================================================================
	void numChannelsChanged() override;
	void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

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
	
	void setSpeakerPosX(int sp, float newPosX);
	void setSpeakerPosY(int sp, float newPosY);
	void setSpeakerPosZ(int sp, float newPosZ);
	
	
	//==============================================================================
	//==============================================================================
	
	AudioParameterCustomBool* bypass;
	AudioParameterCustomFloat* mainVol;
	AudioParameterCustomFloat* xPos;
	AudioParameterCustomFloat* yPos;
	AudioParameterCustomFloat* zPos;
	
	OwnedArray<SpeakerSet> speakerSet;
	std::vector<AudioSampleBuffer> tempIn;
private:
	bool guiFlag;
	float mainVolVal;
	
	//==============================================================================
	//==============================================================================
	
	
	
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UltraPanAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
