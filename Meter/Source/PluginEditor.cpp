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
MeterAudioProcessorEditor::MeterAudioProcessorEditor (MeterAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (chan0Slider = new Slider ("Chan 0 Slider"));
    chan0Slider->setRange (-120, 0, 0);
    chan0Slider->setSliderStyle (Slider::LinearBar);
    chan0Slider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    chan0Slider->addListener (this);

    addAndMakeVisible (chan1Slider = new Slider ("Chan 1 Slider"));
    chan1Slider->setRange (-120, 0, 0);
    chan1Slider->setSliderStyle (Slider::LinearBar);
    chan1Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chan1Slider->addListener (this);

    addAndMakeVisible (chan2Slider = new Slider ("Chan 2 Slider"));
    chan2Slider->setRange (-120, 0, 0);
    chan2Slider->setSliderStyle (Slider::LinearBar);
    chan2Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chan2Slider->addListener (this);

    addAndMakeVisible (chan3Slider = new Slider ("Chan 3 Slider"));
    chan3Slider->setRange (-120, 0, 0);
    chan3Slider->setSliderStyle (Slider::LinearBar);
    chan3Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chan3Slider->addListener (this);

    addAndMakeVisible (chan4Slider = new Slider ("Chan 4 Slider"));
    chan4Slider->setRange (-120, 0, 0);
    chan4Slider->setSliderStyle (Slider::LinearBar);
    chan4Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chan4Slider->addListener (this);

    addAndMakeVisible (chan5Slider = new Slider ("Chan 5 Slider"));
    chan5Slider->setRange (-120, 0, 0);
    chan5Slider->setSliderStyle (Slider::LinearBar);
    chan5Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chan5Slider->addListener (this);

    addAndMakeVisible (chan6Slider = new Slider ("Chan 6 Slider"));
    chan6Slider->setRange (-120, 0, 0);
    chan6Slider->setSliderStyle (Slider::LinearBar);
    chan6Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chan6Slider->addListener (this);

    addAndMakeVisible (chan7Slider = new Slider ("Chan 7 Slider"));
    chan7Slider->setRange (-120, 0, 0);
    chan7Slider->setSliderStyle (Slider::LinearBar);
    chan7Slider->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    chan7Slider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 250);


    //[Constructor] You can add your own custom stuff here..
	startTimer(50);
    //[/Constructor]
}

MeterAudioProcessorEditor::~MeterAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    chan0Slider = nullptr;
    chan1Slider = nullptr;
    chan2Slider = nullptr;
    chan3Slider = nullptr;
    chan4Slider = nullptr;
    chan5Slider = nullptr;
    chan6Slider = nullptr;
    chan7Slider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MeterAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (Font ("Telugu MN", 31.20f, Font::plain));
    g.drawText (TRANS("Meter"),
                21, 15, 91, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MeterAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    chan0Slider->setBounds (24, 56, 152, 16);
    chan1Slider->setBounds (24, 80, 152, 16);
    chan2Slider->setBounds (24, 104, 152, 16);
    chan3Slider->setBounds (24, 128, 152, 16);
    chan4Slider->setBounds (24, 152, 152, 16);
    chan5Slider->setBounds (24, 176, 152, 16);
    chan6Slider->setBounds (24, 200, 152, 16);
    chan7Slider->setBounds (24, 224, 152, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MeterAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == chan0Slider)
    {
        //[UserSliderCode_chan0Slider] -- add your slider handling code here..
        //[/UserSliderCode_chan0Slider]
    }
    else if (sliderThatWasMoved == chan1Slider)
    {
        //[UserSliderCode_chan1Slider] -- add your slider handling code here..
        //[/UserSliderCode_chan1Slider]
    }
    else if (sliderThatWasMoved == chan2Slider)
    {
        //[UserSliderCode_chan2Slider] -- add your slider handling code here..
        //[/UserSliderCode_chan2Slider]
    }
    else if (sliderThatWasMoved == chan3Slider)
    {
        //[UserSliderCode_chan3Slider] -- add your slider handling code here..
        //[/UserSliderCode_chan3Slider]
    }
    else if (sliderThatWasMoved == chan4Slider)
    {
        //[UserSliderCode_chan4Slider] -- add your slider handling code here..
        //[/UserSliderCode_chan4Slider]
    }
    else if (sliderThatWasMoved == chan5Slider)
    {
        //[UserSliderCode_chan5Slider] -- add your slider handling code here..
        //[/UserSliderCode_chan5Slider]
    }
    else if (sliderThatWasMoved == chan6Slider)
    {
        //[UserSliderCode_chan6Slider] -- add your slider handling code here..
        //[/UserSliderCode_chan6Slider]
    }
    else if (sliderThatWasMoved == chan7Slider)
    {
        //[UserSliderCode_chan7Slider] -- add your slider handling code here..
        //[/UserSliderCode_chan7Slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MeterAudioProcessorEditor::timerCallback() {
//	chan0Slider->setValue(processor.level[0];
//	chan1Slider->setValue(processor.level[1];
//	chan2Slider->setValue(processor.level[2];
//	chan3Slider->setValue(processor.level[3];
//	chan4Slider->setValue(processor.level[4];
//	chan5Slider->setValue(processor.level[5];
//	chan6Slider->setValue(processor.level[6];
//	chan7Slider->setValue(processor.level[7];
	chan0Slider->setValue(processor.getChanLevel(0), dontSendNotification);
	chan1Slider->setValue(processor.getChanLevel(1), dontSendNotification);
	chan2Slider->setValue(processor.getChanLevel(2), dontSendNotification);
	chan3Slider->setValue(processor.getChanLevel(3), dontSendNotification);
	chan4Slider->setValue(processor.getChanLevel(4), dontSendNotification);
	chan5Slider->setValue(processor.getChanLevel(5), dontSendNotification);
	chan6Slider->setValue(processor.getChanLevel(6), dontSendNotification);
	chan7Slider->setValue(processor.getChanLevel(7), dontSendNotification);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MeterAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="MeterAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="200" initialHeight="250">
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="21 15 91 30" fill="solid: ff000000" hasStroke="0" text="Meter"
          fontname="Telugu MN" fontsize="31.199999999999999289" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="Chan 0 Slider" id="f8756a61c3ff5ce7" memberName="chan0Slider"
          virtualName="" explicitFocusOrder="0" pos="24 56 152 16" min="-120"
          max="0" int="0" style="LinearBar" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Chan 1 Slider" id="f9085ba56ba3c6b3" memberName="chan1Slider"
          virtualName="" explicitFocusOrder="0" pos="24 80 152 16" min="-120"
          max="0" int="0" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Chan 2 Slider" id="134341ba85f7e34d" memberName="chan2Slider"
          virtualName="" explicitFocusOrder="0" pos="24 104 152 16" min="-120"
          max="0" int="0" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Chan 3 Slider" id="e2b59dd05de0cd11" memberName="chan3Slider"
          virtualName="" explicitFocusOrder="0" pos="24 128 152 16" min="-120"
          max="0" int="0" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Chan 4 Slider" id="f5836031c52187e2" memberName="chan4Slider"
          virtualName="" explicitFocusOrder="0" pos="24 152 152 16" min="-120"
          max="0" int="0" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Chan 5 Slider" id="21fb980554e4d032" memberName="chan5Slider"
          virtualName="" explicitFocusOrder="0" pos="24 176 152 16" min="-120"
          max="0" int="0" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Chan 6 Slider" id="dede3a07f9e86da4" memberName="chan6Slider"
          virtualName="" explicitFocusOrder="0" pos="24 200 152 16" min="-120"
          max="0" int="0" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <SLIDER name="Chan 7 Slider" id="d7ab1e7cc7388bf3" memberName="chan7Slider"
          virtualName="" explicitFocusOrder="0" pos="24 224 152 16" min="-120"
          max="0" int="0" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
