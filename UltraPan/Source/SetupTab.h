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

#ifndef __JUCE_HEADER_F1BDC2894067C900__
#define __JUCE_HEADER_F1BDC2894067C900__

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
class SetupTab  : public Component,
                  public ComboBoxListener,
                  public SliderListener,
                  public ButtonListener
{
public:
    //==============================================================================
    SetupTab (UltraPanAudioProcessor& p);
    ~SetupTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	UltraPanAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<ComboBox> speakerSelectBox;
    ScopedPointer<Slider> speakerPosXSlider;
    ScopedPointer<Slider> speakerPosYSlider;
    ScopedPointer<Slider> speakerPosZSlider;
    ScopedPointer<TextButton> _1;
    ScopedPointer<TextButton> _2;
    ScopedPointer<TextButton> _3;
    ScopedPointer<TextButton> _4;
    ScopedPointer<TextButton> _5;
    ScopedPointer<TextButton> _6;
    ScopedPointer<TextButton> _7;
    ScopedPointer<TextButton> _8;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SetupTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_F1BDC2894067C900__
