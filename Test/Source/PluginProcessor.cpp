/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
TestAudioProcessor::TestAudioProcessor()
: AudioProcessor(BusesProperties()
				 .withInput("Input", AudioChannelSet::mono())
				 .withOutput("Output", AudioChannelSet::discreteChannels(8)))
{
	AudioParameterFloat("gain", "Gain", 0, 1, 0.8);
	AudioParameterInt("source", "Source", 0, 9, 0);
	speakers.setBase(1);
	speakers.setScale(1);
}

TestAudioProcessor::~TestAudioProcessor()
{
}

//==============================================================================
const String TestAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TestAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TestAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double TestAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TestAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TestAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TestAudioProcessor::setCurrentProgram (int index)
{
}

const String TestAudioProcessor::getProgramName (int index)
{
    return String();
}

void TestAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TestAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	tempBuffer.setSize(getTotalNumInputChannels(), samplesPerBlock);
	speakers.setNumSpeakers(getTotalNumOutputChannels());
	
	std::cout<<"Num Inputs: "<<getTotalNumInputChannels()<<std::endl;
	std::cout<<"Num Output: "<<getTotalNumOutputChannels()<<std::endl;
}

void TestAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

bool TestAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
	if ((layouts.getMainInputChannels() > 2) || layouts.getMainOutputChannels() > 8)
		return false;
	else
		return true;
}

void TestAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	const float**	dataRd	= buffer.getArrayOfReadPointers();
	float**			dataWt	= buffer.getArrayOfWritePointers();
	const float**	tempRd	= tempBuffer.getArrayOfReadPointers();
	float**			tempWt	= tempBuffer.getArrayOfWritePointers();
	
	int numIns	= getTotalNumInputChannels();
	int numOuts	= getTotalNumOutputChannels();
	int bufSize	= buffer.getNumSamples();
	
	for (int ch = 0; ch < numIns; ch++) {
		tempBuffer.copyFrom(ch, 0, buffer, ch, 0, buffer.getNumSamples());
	}
	
	buffer.clear();
	for (int in = 0; in < numIns; in++) {
		for (int out = 0; out < numOuts; out++) {
			for (int i = 0; i < bufSize; i++) {
				dataWt[out][i] += tempRd[in][i] * speakers.getSpeakerGain(out);
			}
		}
	}
}

//==============================================================================
bool TestAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TestAudioProcessor::createEditor()
{
    return new TestAudioProcessorEditor (*this);
}

//==============================================================================
void TestAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TestAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TestAudioProcessor();
}
