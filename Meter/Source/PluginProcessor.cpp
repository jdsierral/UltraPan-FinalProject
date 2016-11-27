/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
MeterAudioProcessor::MeterAudioProcessor()
     : AudioProcessor (BusesProperties()
                       .withInput  ("Input",  AudioChannelSet::discreteChannels(8), true)
                       .withOutput ("Output", AudioChannelSet::discreteChannels(8), true))
{
	
}

MeterAudioProcessor::~MeterAudioProcessor()
{
}

//==============================================================================
const String MeterAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool MeterAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool MeterAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double MeterAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int MeterAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int MeterAudioProcessor::getCurrentProgram()
{
    return 0;
}

void MeterAudioProcessor::setCurrentProgram (int index)
{
}

const String MeterAudioProcessor::getProgramName (int index)
{
    return String();
}

void MeterAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void MeterAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void MeterAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool MeterAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
	if (layouts.getMainBusNumInputChannels() == layouts.getMainBusNumOutputChannels()) {
		return true;
	} else {
		return false;
	}
}
#endif

void MeterAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int numInputs  = getTotalNumInputChannels();
    const int numOutputs = getTotalNumOutputChannels();
	const int bufSize = buffer.getNumSamples();
    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
	for (int i = 0; i < numInputs; i++) {
		level[i] = Decibels::gainToDecibels(buffer.getRMSLevel(i, 0, bufSize));
	}
}

//==============================================================================
bool MeterAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* MeterAudioProcessor::createEditor()
{
    return new MeterAudioProcessorEditor (*this);
}

//==============================================================================
void MeterAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void MeterAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new MeterAudioProcessor();
}
