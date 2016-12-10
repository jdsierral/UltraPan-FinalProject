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



//==============================================================================
/**
*/
class UltraPanOscAudioProcessor  : public AudioProcessor,
								   public OSCReceiver,
								   public OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback>
{
public:
    //==============================================================================
    UltraPanOscAudioProcessor();
    ~UltraPanOscAudioProcessor();

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
	
	//==============================================================================
	//==============================================================================
	
	void setGuiFlag() { guiFlag = true; }
	void clearGuiFlag() { guiFlag = false; }
	bool getGuiFlag() { return guiFlag; }
	
	//==============================================================================
	
	AudioParameterCustomFloat* posX;
	AudioParameterCustomFloat* posY;
	AudioParameterCustomFloat* posZ;
	
private:
	
	String address = "127.0.0.1";
	int udpPort = 9001; // dynamically set udp Ports
	
	int processorID = 0;
	
	bool guiFlag;
	
	OSCSender sender;
	
	void msgError (const String& messageText) {
		AlertWindow::showMessageBoxAsync (
            AlertWindow::WarningIcon,
            "Connection error",
            messageText,
            "OK");
	}
	
	void oscMessageReceived (const OSCMessage& message) override {
		if (message.size() == 3 && message[0].isFloat32())
			*posX = message[0].getFloat32();
			*posY = message[1].getFloat32();
			*posZ = message[2].getFloat32();
	}
	
	//==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UltraPanOscAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
