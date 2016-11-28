/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
GraphicsAudioProcessor::GraphicsAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	bypass = new AudioParameterBool("bypass", "Bypass", false);
	gain = new AudioParameterFloat("gain", "Gain", -60, 12, 0);
	
	addParameter(bypass);
	addParameter(gain);
	
}

GraphicsAudioProcessor::~GraphicsAudioProcessor()
{
}

//==============================================================================
const String GraphicsAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool GraphicsAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool GraphicsAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double GraphicsAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int GraphicsAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int GraphicsAudioProcessor::getCurrentProgram()
{
    return 0;
}

void GraphicsAudioProcessor::setCurrentProgram (int index)
{
}

const String GraphicsAudioProcessor::getProgramName (int index)
{
    return String();
}

void GraphicsAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void GraphicsAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
}

void GraphicsAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GraphicsAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void GraphicsAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	const int	  numIns = getTotalNumInputChannels();
	const int	 numOuts = getTotalNumOutputChannels();
	const float** dataRd = buffer.getArrayOfReadPointers();
	float**		  dataWt = buffer.getArrayOfWritePointers();
	const int	 bufSize = buffer.getNumSamples();
	
	buffer.applyGain(Decibels::decibelsToGain<float>(gain->get()));
	ignoreUnused(numIns, numOuts);
	ignoreUnused(dataRd, dataWt, bufSize);
	
}

//==============================================================================
bool GraphicsAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* GraphicsAudioProcessor::createEditor()
{
    return new GraphicsAudioProcessorEditor (*this);
}

//==============================================================================
void GraphicsAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void GraphicsAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GraphicsAudioProcessor();
}
