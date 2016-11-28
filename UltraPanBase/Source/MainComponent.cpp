/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/


#include "MainComponent.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
MainContentComponent::MainContentComponent()
{
	setSize (800, 600);
	
	// specify the number of input and output channels that we want to open
	

	setAudioChannels (numIns, numOuts);
	
}

MainContentComponent::~MainContentComponent()
{
	shutdownAudio();
}

//==============================================================================
void MainContentComponent::prepareToPlay (int samplesPerBlock, double sampleRate)
{
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

void MainContentComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{

	const int bufSize = bufferToFill.buffer->getNumSamples();
	
	float** dataWt = bufferToFill.buffer->getArrayOfWritePointers();
	
	
	for (int in = 0; in < numIns; in++) {
		tempIn[in].copyFrom(0, 0, *bufferToFill.buffer, in, 0, bufSize);
	}
	
	bufferToFill.buffer->clear();
	
	for (int in = 0; in < numIns; in++) {
		speakerSet[in]->compute(tempIn[in], *bufferToFill.buffer);
	}
	
	bufferToFill.buffer->applyGain(mainVolVal);
}

void MainContentComponent::releaseResources()
{

}

//==============================================================================
void MainContentComponent::paint (Graphics& g)
{

	g.fillAll (Colours::black);

}

void MainContentComponent::resized()
{

}

