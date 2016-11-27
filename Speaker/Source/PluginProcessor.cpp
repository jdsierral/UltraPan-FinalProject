/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SpeakerAudioProcessor::SpeakerAudioProcessor()
: AudioProcessor(BusesProperties().withInput("Input", AudioChannelSet::mono())
				 .withOutput("Output", AudioChannelSet::discreteChannels(8)))
{
//	auto xPosCallback = [this] (float newValue) {
//		setGuiFlag();
//	};
//	
//	auto yPosCallback = [this] (float newValue) {
//		setGuiFlag();
//	};
//	
//	auto zPosCallback = [this] (float newValue) {
//		setGuiFlag();
//	};
//	
//	xPos = new AudioParameterCustomFloat("xPos", "X Pos", -10, 10, 0, xPosCallback);
//	yPos = new AudioParameterCustomFloat("yPos", "Y Pos", -10, 10, 0, yPosCallback);
//	zPos = new AudioParameterCustomFloat("zPos", "Z Pos", -10, 10, 0, zPosCallback);
//	
//	addParameter(xPos);
//	addParameter(yPos);
//	addParameter(zPos);
}

SpeakerAudioProcessor::~SpeakerAudioProcessor()
{
//	delete xPos;
//	delete yPos;
//	delete zPos;
}

//==============================================================================
const String SpeakerAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SpeakerAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SpeakerAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double SpeakerAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SpeakerAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SpeakerAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SpeakerAudioProcessor::setCurrentProgram (int index)
{
}

const String SpeakerAudioProcessor::getProgramName (int index)
{
    return String();
}

void SpeakerAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SpeakerAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	int numIns = getTotalNumInputChannels();
	int numOuts = getTotalNumOutputChannels();
	
	while (numIns > speakerSet.size())
		speakerSet.add(new SpeakerSet());
	while (numIns < speakerSet.size())
		speakerSet.removeLast();
	
	tempIn.resize(numIns);
	
	for (int in = 0; in < numIns; in++) {
		tempIn[in].setSize(1, samplesPerBlock);
		speakerSet[in]->setNumSpeakers(numOuts);
		speakerSet[in]->setBufferSize(samplesPerBlock);
	}
}

void SpeakerAudioProcessor::releaseResources()
{
}

bool SpeakerAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
	if (getTotalNumInputChannels() == 1 && getTotalNumOutputChannels() > 1) {
		return true;
	}	else {
		return false;
	}
}

void SpeakerAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int numIns  = getTotalNumInputChannels();
    const int numOuts = getTotalNumOutputChannels();
	const int bufSize = buffer.getNumSamples();
	
	float** dataWt = buffer.getArrayOfWritePointers();
	
	
	for (int in = 0; in < numIns; in++) {
		tempIn[in].copyFrom(0, 0, buffer, 0, 0, bufSize);
	}

	buffer.clear();
	
	for (int in = 0; in < numIns; in++) {
		speakerSet[in]->compute(tempIn[in], buffer);
	}

}

//==============================================================================
bool SpeakerAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SpeakerAudioProcessor::createEditor()
{
    return new SpeakerAudioProcessorEditor (*this);
}

//==============================================================================
void SpeakerAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SpeakerAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SpeakerAudioProcessor();
}
