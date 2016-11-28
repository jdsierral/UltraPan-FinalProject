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

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
UltraPanOscAudioProcessorEditor::UltraPanOscAudioProcessorEditor (UltraPanOscAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (posXSlider = new Slider ("Pos X Slider"));
    posXSlider->setRange (0, 10, 0);
    posXSlider->setSliderStyle (Slider::LinearHorizontal);
    posXSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    posXSlider->addListener (this);

    addAndMakeVisible (posYSlider = new Slider ("Pos Y Slider"));
    posYSlider->setRange (0, 10, 0);
    posYSlider->setSliderStyle (Slider::LinearVertical);
    posYSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    posYSlider->addListener (this);

    addAndMakeVisible (posZSlider = new Slider ("Pos Z Slider"));
    posZSlider->setRange (0, 10, 0);
    posZSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    posZSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    posZSlider->addListener (this);

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::IncDecButtons);
    slider->setTextBoxStyle (Slider::TextBoxLeft, false, 40, 20);
    slider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 300);


    //[Constructor] You can add your own custom stuff here..
	startTimer(50);
    //[/Constructor]
}

UltraPanOscAudioProcessorEditor::~UltraPanOscAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    posXSlider = nullptr;
    posYSlider = nullptr;
    posZSlider = nullptr;
    slider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void UltraPanOscAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (Font (36.70f, Font::plain));
    g.drawText (TRANS("JuanSaudio"),
                0, 33, 200, 30,
                Justification::centred, true);

    g.setColour (Colours::black);
    g.setFont (Font (15.00f, Font::plain));
    g.drawText (TRANS("ID"),
                79, 267, 29, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void UltraPanOscAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    posXSlider->setBounds (40, 248, 150, 24);
    posYSlider->setBounds (8, 96, 32, 150);
    posZSlider->setBounds (8, 248, 31, 24);
    slider->setBounds (109, 276, 83, 15);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void UltraPanOscAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == posXSlider)
    {
        //[UserSliderCode_posXSlider] -- add your slider handling code here..
		*processor.posX = posXSlider->getValue();
        //[/UserSliderCode_posXSlider]
    }
    else if (sliderThatWasMoved == posYSlider)
    {
        //[UserSliderCode_posYSlider] -- add your slider handling code here..
		*processor.posY = posYSlider->getValue();
        //[/UserSliderCode_posYSlider]
    }
    else if (sliderThatWasMoved == posZSlider)
    {
        //[UserSliderCode_posZSlider] -- add your slider handling code here..
		*processor.posZ = posZSlider->getValue();
        //[/UserSliderCode_posZSlider]
    }
    else if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void UltraPanOscAudioProcessorEditor::timerCallback() {
	if (processor.getGuiFlag()) {
		posXSlider->setValue(*processor.posX, dontSendNotification);
		posYSlider->setValue(*processor.posY, dontSendNotification);
		posZSlider->setValue(*processor.posZ, dontSendNotification);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="UltraPanOscAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="UltraPanOscAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(&amp;p), processor(p)"
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="200" initialHeight="300">
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="0 33 200 30" fill="solid: ff000000" hasStroke="0" text="JuanSaudio"
          fontname="Default font" fontsize="36.700000000000002842" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="79 267 29 30" fill="solid: ff000000" hasStroke="0" text="ID"
          fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="Pos X Slider" id="2630984d7f97486a" memberName="posXSlider"
          virtualName="" explicitFocusOrder="0" pos="40 248 150 24" min="0"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Pos Y Slider" id="84413019f18046d3" memberName="posYSlider"
          virtualName="" explicitFocusOrder="0" pos="8 96 32 150" min="0"
          max="10" int="0" style="LinearVertical" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Pos Z Slider" id="c3d91f1c2b1b1b4b" memberName="posZSlider"
          virtualName="" explicitFocusOrder="0" pos="8 248 31 24" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="b9224bcd772ce01a" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="109 276 83 15" min="0" max="10" int="0"
          style="IncDecButtons" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="40" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
