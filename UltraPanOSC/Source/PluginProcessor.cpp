/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
UltraPanOscAudioProcessor::UltraPanOscAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::mono(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::mono(), true)
                     #endif
                       )
#endif
{
	auto posXCallback = [this] (float newVal) {
		if (!sender.send("/UltraPan/" + String(processorID) + "/posX", newVal))
			msgError("Something went wrong on processor" + String(processorID));
		setGuiFlag();
	};
	
	auto posYCallback = [this] (float newVal) {
		if (!sender.send("/UltraPan/" + String(processorID) + "/posY", newVal))
			msgError("Something went wrong on processor" + String(processorID));
		setGuiFlag();
	};
	
	auto posZCallback = [this] (float newVal) {
		if (!sender.send("/UltraPan/" + String(processorID) + "/posZ", newVal))
			msgError("Something went wrong on processor" + String(processorID));
		setGuiFlag();
	};
	
	posX = new AudioParameterCustomFloat
	("posX", "Pos X", -10, 10, 0, posXCallback);
	
	posY = new AudioParameterCustomFloat
	("posY", "Pos Y", -10, 10, 0, posYCallback);
	
	posZ = new AudioParameterCustomFloat
	("posZ", "Pos Z", -10, 10, 0, posZCallback);
	
	addParameter(posX);
	addParameter(posY);
	addParameter(posZ);
	
	if (! sender.connect(address, udpPort))
		msgError("Connection ˆ&*( up... run for your lives");
	
	if (! connect(udpPort + 64))
		msgError("Not Receiving... sssooooorryyy");
	
	OSCReceiver::addListener(this, "/UltraPan/" + String(processorID));
}

UltraPanOscAudioProcessor::~UltraPanOscAudioProcessor()
{
}

//==============================================================================
const String UltraPanOscAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool UltraPanOscAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool UltraPanOscAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double UltraPanOscAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int UltraPanOscAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int UltraPanOscAudioProcessor::getCurrentProgram()
{
    return 0;
}

void UltraPanOscAudioProcessor::setCurrentProgram (int index)
{
}

const String UltraPanOscAudioProcessor::getProgramName (int index)
{
    return String();
}

void UltraPanOscAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void UltraPanOscAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void UltraPanOscAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool UltraPanOscAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void UltraPanOscAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
}

//==============================================================================
bool UltraPanOscAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* UltraPanOscAudioProcessor::createEditor()
{
    return new UltraPanOscAudioProcessorEditor (*this);
}

//==============================================================================
void UltraPanOscAudioProcessor::getStateInformation (MemoryBlock& destData)
{
	XmlElement settings("PluginSettings");
	
	settings.setAttribute(posX->paramID, *posX);
	settings.setAttribute(posY->paramID, *posY);
	settings.setAttribute(posZ->paramID, *posZ);
	
	copyXmlToBinary(settings, destData);
}

void UltraPanOscAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
	ScopedPointer<XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
	
	if (xmlState != nullptr) {
		if (xmlState->hasTagName("PluginSettings")) {
			*posX = xmlState->getDoubleAttribute(posX->paramID);
			*posY = xmlState->getDoubleAttribute(posY->paramID);
			*posZ = xmlState->getDoubleAttribute(posZ->paramID);
		}
	}
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new UltraPanOscAudioProcessor();
}
