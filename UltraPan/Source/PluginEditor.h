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

#ifndef __JUCE_HEADER_766762D71FE39ED6__
#define __JUCE_HEADER_766762D71FE39ED6__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SetupTab.h"
#include "MainTab.h"
#include "OscTab.h"
#include "UltraPanLookAndFeel.h"
#include "SpecialDrawing.h"
#include "Info.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class UltraPanAudioProcessorEditor  : public AudioProcessorEditor,
                                      public Timer,
                                      public ButtonListener
{
public:
    //==============================================================================
    UltraPanAudioProcessorEditor (UltraPanAudioProcessor& p);
    ~UltraPanAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void timerCallback() override;
	void update();
	void updateNumChannels(int ins, int outs);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void visibilityChanged() override;
    void focusGained (FocusChangeType cause) override;
    void focusLost (FocusChangeType cause) override;

    // Binary resources:
    static const char* background3_png;
    static const int background3_pngSize;
    static const char* logoTypeblue_png;
    static const int logoTypeblue_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    UltraPanAudioProcessor& processor;

	const int ins;
	const int outs;

	UltraPanLookAndFeel myLookAndFeel;
	std::vector<SpDraw> sourceDraw;
	std::vector<SpDraw> speakerDraw;
	std::vector<Vector3D<float>> sourcePos;
	std::vector<Vector3D<float>> speakerPos;

	float sliderRange = 10;

	MainTab*	mainTab;
	SetupTab*	setupTab;
	OscTab*		oscTab;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TabbedComponent> tabs;
    ScopedPointer<ToggleButton> bypassButton;
    ScopedPointer<ImageButton> imageButton;
    ScopedPointer<Info> infoOverlay;
    Image cachedImage_background3_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (UltraPanAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_766762D71FE39ED6__
