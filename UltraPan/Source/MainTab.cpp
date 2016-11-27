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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainTab::MainTab (UltraPanAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (mainVolSlider = new Slider ("Main Volume Slider"));
    mainVolSlider->setRange (-60, 12, 0);
    mainVolSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    mainVolSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    mainVolSlider->addListener (this);

    addAndMakeVisible (baseSlider = new Slider ("Base Slider"));
    baseSlider->setRange (1, 1000, 0);
    baseSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    baseSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    baseSlider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 120);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainTab::~MainTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mainVolSlider = nullptr;
    baseSlider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mainVolSlider->setBounds (512, 24, 72, 80);
    baseSlider->setBounds (432, 80, 72, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MainTab::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == mainVolSlider)
    {
        //[UserSliderCode_mainVolSlider] -- add your slider handling code here..
		*processor.mainVol = mainVolSlider->getValue();
        //[/UserSliderCode_mainVolSlider]
    }
    else if (sliderThatWasMoved == baseSlider)
    {
        //[UserSliderCode_baseSlider] -- add your slider handling code here..
		processor.setBase(baseSlider->getValue());
        //[/UserSliderCode_baseSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainTab" componentName=""
                 parentClasses="public Component" constructorParams="UltraPanAudioProcessor&amp; p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="600"
                 initialHeight="120">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="Main Volume Slider" id="48e517a99b24c0fe" memberName="mainVolSlider"
          virtualName="" explicitFocusOrder="0" pos="512 24 72 80" min="-60"
          max="12" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Base Slider" id="271c0bce09620c47" memberName="baseSlider"
          virtualName="" explicitFocusOrder="0" pos="432 80 72 24" min="1"
          max="1000" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxLeft"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
