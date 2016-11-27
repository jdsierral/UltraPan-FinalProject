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
     : AudioProcessor (BusesProperties()
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                       .withOutput ("Output", AudioChannelSet::discreteChannels(8), true))
{
	auto genCallback = [this] (float newValue) {
		setGuiFlag();
	};
	
	auto mainVolCallback = [this] (float newValue) {
		mainVolVal = Decibels::decibelsToGain(newValue, -60.f);
		setGuiFlag();
	};
	
	auto xPosCallback = [this] (float newValue) {
		for (int in = 0; in < getMainBusNumInputChannels(); in++) {
			speakerSet[in]->setSourcePosX(newValue);
		}
		setGuiFlag();
	};
	
	auto yPosCallback = [this] (float newValue) {
		for (int in = 0; in < getMainBusNumInputChannels(); in++) {
			speakerSet[in]->setSourcePosY(newValue);
		}
		setGuiFlag();
	};
	
	auto zPosCallback = [this] (float newValue) {
		for (int in = 0; in < getMainBusNumInputChannels(); in++) {
			speakerSet[in]->setSourcePosZ(newValue);
		}
		setGuiFlag();
	};
	
	bypass = new AudioParameterCustomBool
	("bypass", "Bypass", false, genCallback);
	mainVol = new AudioParameterCustomFloat
	("mainVol", "Volume", -60, 12, 0, mainVolCallback);
	xPos = new AudioParameterCustomFloat
	("xPos", "X Pos", -10, 10, 0, xPosCallback);
	yPos = new AudioParameterCustomFloat
	("yPos", "Y Pos", -10, 10, 0, yPosCallback);
	zPos = new AudioParameterCustomFloat
	("zPos", "Z Pos", -10, 10, 0, zPosCallback);
	
	addParameter(bypass);
	addParameter(mainVol);
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
void UltraPanAudioProcessor::numChannelsChanged()
{
	int numIns = getTotalNumInputChannels();
	int numOuts = getTotalNumOutputChannels();
	
	while (numIns > speakerSet.size())
		speakerSet.add(new SpeakerSet());
	while (numIns < speakerSet.size())
		speakerSet.removeLast();
	
	tempIn.resize(numIns);
	
	for (int in = 0; in < numIns; in++) {
		speakerSet[in]->setNumSpeakers(numOuts);
		speakerSet[in]->init(getSampleRate());
	}
}


void UltraPanAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
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
		speakerSet[in]->init(sampleRate);
		speakerSet[in]->setBufferSize(samplesPerBlock);
	}
}

void UltraPanAudioProcessor::releaseResources()
{
}

bool UltraPanAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
	if (layouts.getMainInputChannels() < layouts.getMainOutputChannels()) {
		return true;
	}
	else return false;
}

void UltraPanAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	const int numIns  = getTotalNumInputChannels();
	const int numOuts = getTotalNumOutputChannels();
	const int bufSize = buffer.getNumSamples();
	
	float** dataWt = buffer.getArrayOfWritePointers();
	
	
	for (int in = 0; in < numIns; in++) {
		tempIn[in].copyFrom(0, 0, buffer, in, 0, bufSize);
	}
	
	buffer.clear();
	
	for (int in = 0; in < numIns; in++) {
		speakerSet[in]->compute(tempIn[in], buffer);
	}
	
	buffer.applyGain(mainVolVal);
}


//==============================================================================
//==============================================================================


void UltraPanAudioProcessor::setSpeakerPosX(int sp, float newPosX){
	for (int in = 0; in < getTotalNumInputChannels(); in++) {
		speakerSet[in]->setSpeakerPosX(sp, newPosX);
	}
}

void UltraPanAudioProcessor::setSpeakerPosY(int sp, float newPosY){
	for (int in = 0; in < getTotalNumInputChannels(); in++) {
		speakerSet[in]->setSpeakerPosY(sp, newPosY);
	}
}

void UltraPanAudioProcessor::setSpeakerPosZ(int sp, float newPosZ){
	for (int in = 0; in < getTotalNumInputChannels(); in++) {
		speakerSet[in]->setSpeakerPosZ(sp, newPosZ);
	}
}

void UltraPanAudioProcessor::setBase(float newBase){
	for (int in = 0; in < getTotalNumInputChannels(); in++) {
		speakerSet[in]->setBase(1 + newBase/1000.f);
	}
}


//==============================================================================
//==============================================================================
bool UltraPanAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* UltraPanAudioProcessor::createEditor()
{
	int numIns = getTotalNumInputChannels();
	int numOuts = getTotalNumOutputChannels();
	
	while (numIns > speakerSet.size())
		speakerSet.add(new SpeakerSet());
	while (numIns < speakerSet.size())
		speakerSet.removeLast();
	
	tempIn.resize(numIns);
	
	for (int in = 0; in < numIns; in++) {
		speakerSet[in]->setNumSpeakers(numOuts);
		speakerSet[in]->init(getSampleRate());
	}
	
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
