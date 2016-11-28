/*
  ==============================================================================

    MainComponent.h
    Created: 28 Nov 2016 4:47:56am
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SpeakerSet.h"

class MainContentComponent   : public AudioAppComponent
{
public:
	//==============================================================================
	
	MainContentComponent();
	~MainContentComponent();
	
	//==============================================================================
	
	void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
	void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override;
	void releaseResources() override;
	
	
	//==============================================================================
	
	void paint (Graphics& g) override;
	void resized() override;
	
	
	
	OwnedArray<SpeakerSet> speakerSet;
	std::vector<AudioSampleBuffer> tempIn;
private:
	//==============================================================================
	
	int numIns = 12;
	int numOuts = 12;
	
	float mainVolVal;
	
	
	
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


// (This function is called by the app startup code to create our main component)
Component* createMainContentComponent()     { return new MainContentComponent(); }




#endif  // MAINCOMPONENT_H_INCLUDED
