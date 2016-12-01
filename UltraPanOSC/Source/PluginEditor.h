/*
 ==============================================================================
 
 This is an automatically generated GUI class created by the Projucer!
 
 Be careful when adding custom code to these files, as only the code within
 the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
 and re-saved.
 
 Created with Projucer version: 4.3.0
 
 ------------------------------------------------------------------------------
 
 The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
 Copyright (c) 2015 - ROLI Ltd.
 
 ==============================================================================
 */

#ifndef __JUCE_HEADER_7670B8709D53D31B__
#define __JUCE_HEADER_7670B8709D53D31B__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "libgametrak/GameTrak.h"

using namespace gametrak;
//[/Headers]



//==============================================================================
/**
 //[Comments]
 An auto-generated component, created by the Projucer.
 
 Describe your class and how it works here!
 //[/Comments]
 */
class UltraPanOscAudioProcessorEditor  : public AudioProcessorEditor,
public Timer,
public SliderListener
{
public:
	//==============================================================================
	UltraPanOscAudioProcessorEditor (UltraPanOscAudioProcessor& p);
	~UltraPanOscAudioProcessorEditor();
	
	//==============================================================================
	//[UserMethods]     -- You can add your own custom methods in this section.
	void timerCallback() override;
	
	GameTrak *gt = 0 ;
	TimeStamp::inttime last_time = 0 ;
	bool button_pressed = false ;
	
	void printInfo(TimeStamp::inttime timestamp,
				   double leftx, double lefty, double leftz,
				   double rightx, double righty, double rightz,
				   bool button) {
  double freq = 1/((timestamp - last_time) * 1.0E-9);
  std::cout << timestamp << " ns, "
		<< std::setw(7) << freq << " Hz, "
		<< "Left: (" << std::setw(3) << leftx << ", " << std::setw(3) << lefty << ", " << std::setw(3) << leftz << ") mm"
		<< ", Right: (" << std::setw(3) << rightx << ", " << std::setw(3) << rightx << ", " << std::setw(3) << rightz << ") mm, "
		<< "button: " << button << std::endl ;
	}
	
	//[/UserMethods]
	
	void paint (Graphics& g) override;
	void resized() override;
	void sliderValueChanged (Slider* sliderThatWasMoved) override;
	
	
	
private:
	//[UserVariables]   -- You can add your own custom variables in this section.
	UltraPanOscAudioProcessor& processor;
	
	bool usePullMode = false;//true;
	//////////////////////////////////////////////////////////
	
	
	
	
	
	
	//[/UserVariables]
	
	//==============================================================================
	ScopedPointer<Slider> posXSlider;
	ScopedPointer<Slider> posYSlider;
	ScopedPointer<Slider> posZSlider;
	ScopedPointer<Slider> slider;
	
	
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UltraPanOscAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7670B8709D53D31B__
