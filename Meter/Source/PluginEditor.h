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

#ifndef __JUCE_HEADER_7666870200CB4E20__
#define __JUCE_HEADER_7666870200CB4E20__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MeterAudioProcessorEditor  : public AudioProcessorEditor,
                                   public Timer,
                                   public SliderListener
{
public:
    //==============================================================================
    MeterAudioProcessorEditor (MeterAudioProcessor& p);
    ~MeterAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void timerCallback() override;
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    MeterAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> chan0Slider;
    ScopedPointer<Slider> chan1Slider;
    ScopedPointer<Slider> chan2Slider;
    ScopedPointer<Slider> chan3Slider;
    ScopedPointer<Slider> chan4Slider;
    ScopedPointer<Slider> chan5Slider;
    ScopedPointer<Slider> chan6Slider;
    ScopedPointer<Slider> chan7Slider;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MeterAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7666870200CB4E20__
