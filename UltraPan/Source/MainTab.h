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

#ifndef __JUCE_HEADER_F72CDE6AC5E93B08__
#define __JUCE_HEADER_F72CDE6AC5E93B08__

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
class MainTab  : public Component,
                 public SliderListener,
                 public ButtonListener,
                 public ComboBoxListener
{
public:
    //==============================================================================
    MainTab (UltraPanAudioProcessor& p);
    ~MainTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void update();
	void updateNumChannels(int ins, int outs);


    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	UltraPanAudioProcessor& processor;

	Vector3D<float> l;
	Vector3D<float> r;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> mainVolSlider;
    ScopedPointer<Slider> baseSlider;
    ScopedPointer<Slider> pos1XSlider;
    ScopedPointer<Slider> pos1YSlider;
    ScopedPointer<Slider> pos1ZSlider;
    ScopedPointer<Slider> pos2XSlider;
    ScopedPointer<Slider> pos2YSlider;
    ScopedPointer<Slider> pos2ZSlider;
    ScopedPointer<ToggleButton> toggleButton;
    ScopedPointer<ComboBox> inputSelectBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_F72CDE6AC5E93B08__
