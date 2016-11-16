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
#include "SpeakeSystem.h"


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
	
	void setGuiFlag() {
		guiFlag = true;
	}
	
	void clearGuiFlag() {
		guiFlag = false;
	}
	
	bool getGuiFlag() {
		return guiFlag;
	}

	
	ScopedPointer<AudioParameterCustomFloat> xPos;
	ScopedPointer<AudioParameterCustomFloat> yPos;
	ScopedPointer<AudioParameterCustomFloat> zPos;
	
	
	
private:
	std::vector<float> gain;
	
	std::vector<Vector3D<float>> pos;
	
	AudioSampleBuffer input;
	SpeakerSystem* speakers;
	
	const int numChan = 8;//getTotalNumOutputChannels();
	
	bool guiFlag;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UltraPanAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
