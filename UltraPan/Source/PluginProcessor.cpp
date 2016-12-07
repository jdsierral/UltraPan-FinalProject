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
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                       .withOutput ("Output", AudioChannelSet::discreteChannels(16) , true))
#endif
{
	auto genCallback = [this] (float newValue) {
		setGuiFlag();
	};
	
	auto mainVolCallback = [this] (float newValue) {
		mainVolVal = Decibels::decibelsToGain(newValue, -60.f);
		setGuiFlag();
	};
	
	auto baseCallback = [this] (float newValue) {
		setBase(newValue);
	};
	
	auto pos1XCallback = [this] (float newValue) {
		if (speakerSet.size() > 0)
			speakerSet[0]->setSourcePosX(newValue);
		setGuiFlag();
	};
	
	auto pos1YCallback = [this] (float newValue) {
		if (speakerSet.size() > 0)
			speakerSet[0]->setSourcePosY(newValue);
		setGuiFlag();
	};
	
	auto pos1ZCallback = [this] (float newValue) {
		if (speakerSet.size() > 0)
			speakerSet[0]->setSourcePosZ(newValue);
		setGuiFlag();
	};
	
	auto pos2XCallback = [this] (float newValue) {
		if (speakerSet.size() > 1)
			speakerSet[1]->setSourcePosX(newValue);
		setGuiFlag();
	};
	
	auto pos2YCallback = [this] (float newValue) {
		if (speakerSet.size() > 1)
			speakerSet[1]->setSourcePosY(newValue);
		setGuiFlag();
	};
	
	auto pos2ZCallback = [this] (float newValue) {
		if (speakerSet.size() > 1)
			speakerSet[1]->setSourcePosZ(newValue);
		setGuiFlag();
	};
	
	bypass = new AudioParameterCustomBool
	("bypass", "Bypass", false, genCallback);
	mainVol = new AudioParameterCustomFloat
	("mainVol", "Volume", -60, 12, 0, mainVolCallback);
	base = new AudioParameterCustomFloat
	("base", "Base", 0, 1000, 3, baseCallback);
	
	pos1X = new AudioParameterCustomFloat
	("xPosL", "X Pos Left", -10, 10, 0, pos1XCallback);
	pos1Y = new AudioParameterCustomFloat
	("yPosL", "Y Pos Left", -10, 10, 0, pos1YCallback);
	pos1Z = new AudioParameterCustomFloat
	("zPosL", "Z Pos Left", -10, 10, 0, pos1ZCallback);
	
	pos2X = new AudioParameterCustomFloat
	("xPosR", "X Pos Right", -10, 10, 0, pos2XCallback);
	pos2Y = new AudioParameterCustomFloat
	("yPosR", "Y Pos Right", -10, 10, 0, pos2YCallback);
	pos2Z = new AudioParameterCustomFloat
	("zPosR", "Z Pos Right", -10, 10, 0, pos2ZCallback);
	
	Decibels::gainToDecibels(0, -60);
	
	
	addParameter(bypass);
	addParameter(mainVol);
	addParameter(base);
	
	addParameter(pos1X);
	addParameter(pos1Y);
	addParameter(pos1Z);
	
	addParameter(pos2X);
	addParameter(pos2Y);
	addParameter(pos2Z);
	
	*mainVol = 0;
	*base = 3;
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
	
	UltraPanAudioProcessorEditor* editor = (UltraPanAudioProcessorEditor*)getActiveEditor();
	editor->updateNumChannels(numIns, numOuts);
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool UltraPanAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
	if (layouts.getMainInputChannels() < layouts.getMainOutputChannels()) {
		return true;
	}
	else return false;
}
#endif

bool UltraPanAudioProcessor::canAddBus (bool isInputBus) const {
	const int ins = getTotalNumInputChannels();
	const int outs = getTotalNumOutputChannels();
	
	if (isInputBus) {
		if (ins >= 2) return false;
		else return true;
	} else {
		if (outs >= 16) return false;
		else return true;
	}
}

bool UltraPanAudioProcessor::canRemoveBus (bool isInputBus) const {
	const int ins = getTotalNumInputChannels();
	const int outs = getTotalNumOutputChannels();
	
	if (isInputBus) {
		if (ins == 1) return false;
		else return true;
	} else {
		if (outs == 1) return false;
		else return true;
	}
	
}




//==============================================================================
//==============================================================================


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
	setBase(*base);
}

void UltraPanAudioProcessor::releaseResources()
{
}

void UltraPanAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
	const int numIns  = getTotalNumInputChannels();
//	const int numOuts = getTotalNumOutputChannels();
	const int bufSize = buffer.getNumSamples();
	
//	float** dataWt = buffer.getArrayOfWritePointers();
	
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

void UltraPanAudioProcessor::setSpeakerPos(int sp, Vector3D<float> newPos){
	for (int in = 0; in < getTotalNumInputChannels(); in++) {
		speakerSet[in]->setSpeakerPos(sp, newPos);
	}
	setGuiFlag();
}

void UltraPanAudioProcessor::setSpeakerPosX(int sp, float newPosX){
	for (int in = 0; in < getTotalNumInputChannels(); in++) {
		speakerSet[in]->setSpeakerPosX(sp, newPosX);
	}
	setGuiFlag();
}

void UltraPanAudioProcessor::setSpeakerPosY(int sp, float newPosY){
	for (int in = 0; in < getTotalNumInputChannels(); in++) {
		speakerSet[in]->setSpeakerPosY(sp, newPosY);
	}
	setGuiFlag();
}

void UltraPanAudioProcessor::setSpeakerPosZ(int sp, float newPosZ){
	for (int in = 0; in < getTotalNumInputChannels(); in++) {
		speakerSet[in]->setSpeakerPosZ(sp, newPosZ);
	}
	setGuiFlag();
}

void UltraPanAudioProcessor::setBase(float newBase){
	for (int in = 0; in < getTotalNumInputChannels(); in++) {
		speakerSet[in]->setBase(1 + newBase/1000.f);
	}
	setGuiFlag();
}

//==============================================================================

Vector3D<float> UltraPanAudioProcessor::getSourcePos (int sc){
	return speakerSet[sc]->getSourcePosition();
}

Vector3D<float> UltraPanAudioProcessor::getSpeakerPos (int sp){
	return speakerSet[0]->getSpeakerPos(sp);
}

float UltraPanAudioProcessor::getSpeakerPosX(int sp, float newPosX){
	return speakerSet[0]->getSpeakerPos(sp).x;
}

float UltraPanAudioProcessor::getSpeakerPosY(int sp, float newPosX){
	return speakerSet[0]->getSpeakerPos(sp).y;
}

float UltraPanAudioProcessor::getSpeakerPosZ(int sp, float newPosX){
	return speakerSet[0]->getSpeakerPos(sp).z;
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
	const int ins = getTotalNumInputChannels();
	const int outs = getTotalNumOutputChannels();
	
	XmlElement config ("PluginConfig");
	
	config.setAttribute("NumIns",  ins);
	config.setAttribute("NumOuts", outs);
	
	config.setAttribute(mainVol->paramID, *mainVol);
	config.setAttribute(base->paramID, *base);
	
	//===================================
	config.setAttribute(pos1X->paramID, *pos1X);
	config.setAttribute(pos1Y->paramID, *pos1Y);
	config.setAttribute(pos1Z->paramID, *pos1Z);
	//==========================================
	if (ins > 1) {
		config.setAttribute(pos2X->paramID, *pos2X);
		config.setAttribute(pos2Y->paramID, *pos2Y);
		config.setAttribute(pos2Z->paramID, *pos2Z);
	}
	//==========================================
	for (int out = 0; out < outs; out++) {
		config.setAttribute(speakerSet[0]->getSpeakerName(out) + "PosX",
							speakerSet[0]->getSpeakerPos(out).x);
		config.setAttribute(speakerSet[0]->getSpeakerName(out) + "PosY",
							speakerSet[0]->getSpeakerPos(out).y);
		config.setAttribute(speakerSet[0]->getSpeakerName(out) + "PosZ",
							speakerSet[0]->getSpeakerPos(out).z);
	}
	
	copyXmlToBinary(config, destData);
	DBG(config.getAllSubText());
}

void UltraPanAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	ScopedPointer<XmlElement> xml(getXmlFromBinary(data, sizeInBytes));
	
	if (xml != nullptr) {
		if (xml->hasTagName("PluginConfig")) {
			
			const int ins = xml->getDoubleAttribute("NumIns");
			const int outs= xml->getDoubleAttribute("NumOuts");
			
			*mainVol =  xml->getDoubleAttribute(mainVol->paramID);
			*base = xml->getDoubleAttribute(base->paramID);
			*pos1X = xml->getDoubleAttribute(pos1X->paramID);
			*pos1Y = xml->getDoubleAttribute(pos1Y->paramID);
			*pos1Z = xml->getDoubleAttribute(pos1Z->paramID);
			
			if (ins > 1) {
				*pos2X = xml->getDoubleAttribute(pos2X->paramID);
				*pos2Y = xml->getDoubleAttribute(pos2Y->paramID);
				*pos2Z = xml->getDoubleAttribute(pos2Z->paramID);
			}
			
			for (int out = 0; out < outs; out++) {
				float x, y, z;
				x = xml->getDoubleAttribute(speakerSet[0]->getSpeakerName(out) + "PosX");
				y = xml->getDoubleAttribute(speakerSet[0]->getSpeakerName(out) + "PosY");
				z = xml->getDoubleAttribute(speakerSet[0]->getSpeakerName(out) + "PosZ");
				
				setSpeakerPosX(out, x);
				setSpeakerPosY(out, y);
				setSpeakerPosZ(out, z);
			}
		}
	}
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new UltraPanAudioProcessor();
}
