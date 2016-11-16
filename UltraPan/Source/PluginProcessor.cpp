/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
UltraPanAudioProcessor::UltraPanAudioProcessor()
{
	
	
	gain.resize(numChan);
	pos.resize(numChan);
	
	speakers = new SpeakerSystem(numChan);
	
	for (int i = 0; i < numChan; i++) {
		gain[i] = 1;
	}
	
	auto xPosCallback = [this] (float newValue) {
		speakers->setSourcePosX(newValue);
		setGuiFlag();
	};

	auto yPosCallback = [this] (float newValue) {
		speakers->setSourcePosY(newValue);
		setGuiFlag();
	};

	auto zPosCallback = [this] (float newValue) {
		speakers->setSourcePosZ(newValue);
		setGuiFlag();
	};

	xPos = new AudioParameterCustomFloat("xPos", "X Pos", -10, 10, 0, xPosCallback);
	yPos = new AudioParameterCustomFloat("yPos", "Y Pos", -10, 10, 0, yPosCallback);
	zPos = new AudioParameterCustomFloat("zPos", "Z Pos", -10, 10, 0, zPosCallback);
	
	addParameter(xPos);
	addParameter(yPos);
	addParameter(zPos);
	
}

UltraPanAudioProcessor::~UltraPanAudioProcessor()
{
}

//==============================================================================
const String UltraPanAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool UltraPanAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool UltraPanAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double UltraPanAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int UltraPanAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int UltraPanAudioProcessor::getCurrentProgram()
{
    return 0;
}

void UltraPanAudioProcessor::setCurrentProgram (int index)
{
}

const String UltraPanAudioProcessor::getProgramName (int index)
{
    return String();
}

void UltraPanAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void UltraPanAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	int numOutputs = getTotalNumOutputChannels();
	
	for (int i = 0; i < numOutputs; i++) {
		speakers->setSpeakerPos(i, Vector3D<float>(0.f, 0.f, 0.f));
	}
	
	input.setSize(numOutputs, samplesPerBlock);
	
}

void UltraPanAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool UltraPanAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void UltraPanAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int numInputs  = getTotalNumInputChannels();
    const int numOutputs = getTotalNumOutputChannels();
	const int bufSize = buffer.getNumSamples();
	
	for (int i = 0; i < numOutputs; i++) {
		input.copyFrom(i, 0, buffer, 0, 0, buffer.getNumSamples());
	}
	
	for (int chan = 0; chan < numOutputs; chan++) {
		float* out = buffer.getWritePointer(chan);
		const float* in = buffer.getReadPointer(chan);
		for (int i = 0; i < bufSize; i++) {
			out[i] = in[i] * speakers->getGain(i);
		}
	}
}

//==============================================================================
bool UltraPanAudioProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* UltraPanAudioProcessor::createEditor()
{
    return new UltraPanAudioProcessorEditor (*this);
}

//==============================================================================
void UltraPanAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void UltraPanAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new UltraPanAudioProcessor();
}
