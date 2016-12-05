/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
GeneratorAudioProcessor::GeneratorAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     :	AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	gain = new AudioParameterFloat("Gain", "gain", -60, 12, 0);
	freq = new AudioParameterFloat("Freq", "freq", 0, 20, 1);
	type = new AudioParameterChoice("Type", "type", typesInit(), 0);
	
	addParameter(gain);
	addParameter(freq);
	addParameter(type);
	
	sineOsc.buildUserInterface(&sineParams);
	
	
}

GeneratorAudioProcessor::~GeneratorAudioProcessor()
{
}

//==============================================================================
const String GeneratorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool GeneratorAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool GeneratorAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double GeneratorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int GeneratorAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int GeneratorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void GeneratorAudioProcessor::setCurrentProgram (int index)
{
}

const String GeneratorAudioProcessor::getProgramName (int index)
{
    return String();
}

void GeneratorAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void GeneratorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	sineOsc.init(sampleRate);
}

void GeneratorAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GeneratorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void GeneratorAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	const int outs = getTotalNumOutputChannels();
	const int bufSize = buffer.getNumSamples();
	
	buffer.clear();
	
	float** dataWt = buffer.getArrayOfWritePointers();
	
	switch (type->getIndex()) {
		case types::sine:
			sineOsc.compute(bufSize, NULL, dataWt);
			break;
		case types::white:
			for (int i = 0; i < bufSize; i++) {
				dataWt[0][i] = 2 * (noise.nextFloat()-0.5) *
				Decibels::decibelsToGain<float>(*gain, -60.f);
			}
			break;
		case types::pink:
			for (int i = 0; i < bufSize; i++) {
				dataWt[0][i] = pinkNoise.tick();
			}
			break;
  default:
			buffer.clear();
			break;
	}
	
	for (int chan = 1; chan < outs; chan++) {
		buffer.copyFrom(chan, 0, buffer, 0, 0, bufSize);
	}
}

//==============================================================================
bool GeneratorAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* GeneratorAudioProcessor::createEditor()
{
    return new GeneratorAudioProcessorEditor (*this);
}

//==============================================================================
void GeneratorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void GeneratorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GeneratorAudioProcessor();
}
