/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
BusTestAudioProcessor::BusTestAudioProcessor()
: AudioProcessor(BusesProperties().withInput("Input", AudioChannelSet::stereo())
				 .withOutput("Output", AudioChannelSet::stereo())
				 .withInput("SideChain", AudioChannelSet::mono()))
{
}

BusTestAudioProcessor::~BusTestAudioProcessor()
{
}

//==============================================================================
const String BusTestAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool BusTestAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool BusTestAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double BusTestAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int BusTestAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int BusTestAudioProcessor::getCurrentProgram()
{
    return 0;
}

void BusTestAudioProcessor::setCurrentProgram (int index)
{
}

const String BusTestAudioProcessor::getProgramName (int index)
{
    return String();
}

void BusTestAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void BusTestAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	const int numCh = getChannelCountOfBus(true, 0);
	channelActive.resize(numCh);
	
}

void BusTestAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

bool BusTestAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
	if (layouts.getMainOutputChannels() == 2 &&
		layouts.getMainInputChannels() == 2) {
		return true;
	} else {
		return false;
	}
}

void BusTestAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	const float ** dataRead = buffer.getArrayOfReadPointers();
	float ** dataWrite = buffer.getArrayOfWritePointers();
	
	float scLevel = buffer.getRMSLevel(2, 0, buffer.getNumSamples());
	
	for (int ch = 0; ch < 2; ch++) {
		for (int i = 0; i < buffer.getNumSamples(); i++) {
			dataWrite [ch][i] = dataRead[ch][i] * scLevel * gain;
		}
	}
}

//==============================================================================
bool BusTestAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* BusTestAudioProcessor::createEditor()
{
    return new BusTestAudioProcessorEditor (*this);
}

//==============================================================================
void BusTestAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void BusTestAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new BusTestAudioProcessor();
}
