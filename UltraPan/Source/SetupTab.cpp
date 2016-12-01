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

#include "SetupTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SetupTab::SetupTab (UltraPanAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (speakerSelectBox = new ComboBox ("new combo box"));
    speakerSelectBox->setEditableText (false);
    speakerSelectBox->setJustificationType (Justification::centredLeft);
    speakerSelectBox->setTextWhenNothingSelected (String());
    speakerSelectBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    speakerSelectBox->addListener (this);

    addAndMakeVisible (speakerPosXSlider = new Slider ("Speaker Pos X Slider"));
    speakerPosXSlider->setRange (-10, 10, 0);
    speakerPosXSlider->setSliderStyle (Slider::LinearHorizontal);
    speakerPosXSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    speakerPosXSlider->setColour (Slider::textBoxBackgroundColourId, Colour (0x00ffffff));
    speakerPosXSlider->addListener (this);

    addAndMakeVisible (speakerPosYSlider = new Slider ("Speaker Pos Y Slider"));
    speakerPosYSlider->setRange (-10, 10, 0);
    speakerPosYSlider->setSliderStyle (Slider::LinearHorizontal);
    speakerPosYSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    speakerPosYSlider->addListener (this);

    addAndMakeVisible (speakerPosZSlider = new Slider ("Speaker Pos Z Slider"));
    speakerPosZSlider->setRange (-10, 10, 0);
    speakerPosZSlider->setSliderStyle (Slider::LinearHorizontal);
    speakerPosZSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    speakerPosZSlider->addListener (this);

    addAndMakeVisible (_1 = new TextButton ("new button"));
    _1->setButtonText (TRANS("1"));
    _1->addListener (this);

    addAndMakeVisible (_2 = new TextButton ("new button"));
    _2->setButtonText (TRANS("2"));
    _2->addListener (this);

    addAndMakeVisible (_3 = new TextButton ("new button"));
    _3->setButtonText (TRANS("3"));
    _3->addListener (this);

    addAndMakeVisible (_4 = new TextButton ("new button"));
    _4->setButtonText (TRANS("4"));
    _4->addListener (this);

    addAndMakeVisible (_5 = new TextButton ("new button"));
    _5->setButtonText (TRANS("5"));
    _5->addListener (this);

    addAndMakeVisible (_6 = new TextButton ("new button"));
    _6->setButtonText (TRANS("6"));
    _6->addListener (this);

    addAndMakeVisible (_7 = new TextButton ("new button"));
    _7->setButtonText (TRANS("7"));
    _7->addListener (this);

    addAndMakeVisible (_8 = new TextButton ("new button"));
    _8->setButtonText (TRANS("8"));
    _8->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 120);


    //[Constructor] You can add your own custom stuff here..
	for (int sp = 0; sp < processor.getTotalNumOutputChannels();){
		sp++;
		speakerSelectBox->addItem("Speaker: " + String(sp), sp);
	}
	speakerSelectBox->setSelectedItemIndex(0);
    //[/Constructor]
}

SetupTab::~SetupTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    speakerSelectBox = nullptr;
    speakerPosXSlider = nullptr;
    speakerPosYSlider = nullptr;
    speakerPosZSlider = nullptr;
    _1 = nullptr;
    _2 = nullptr;
    _3 = nullptr;
    _4 = nullptr;
    _5 = nullptr;
    _6 = nullptr;
    _7 = nullptr;
    _8 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SetupTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setGradientFill (ColourGradient (Colour (0xff71c100),
                                       304.0f, 120.0f,
                                       Colour (0xff4b8100),
                                       304.0f, 0.0f,
                                       false));
    g.fillRect (-9, -3, 617, 131);

    //[UserPaint] Add your own custom painting code here..

	chanHor = y * (speakerPosXSlider->getMaximum()-x)/(speakerPosXSlider->getMaximum()-speakerPosXSlider->getMinimum());
	chanVer = - z * (speakerPosYSlider->getMaximum()-x)/(speakerPosYSlider->getMaximum()-speakerPosYSlider->getMinimum());
	chanVerS= (speakerPosYSlider->getMaximum()-x) * (speakerPosYSlider->getMaximum()-x)/(speakerPosXSlider->getMaximum()-speakerPosXSlider->getMinimum());
	radi = 15 * (((speakerPosXSlider->getMaximum()-x)/(speakerPosXSlider->getMaximum()-speakerPosXSlider->getMinimum())) * 0.9 + 0.1);


	g.setColour (Colour (0xb3000000));
	g.fillEllipse (baseHor - radi + 5 * chanHor,
				   baseVer - radi + 2 * chanVerS + 85,
				   radi * 2,
				   radi / 2);

	g.setGradientFill (ColourGradient (Colour (0xffb9a384),
									   baseHor + 5.75 * (chanHor),
									   baseVer + 5 * (chanVer) - radi,
									   Colour (0xff574326),
									   baseHor + 4.25 * (chanHor),
									   baseVer + 5 * (chanVer) + radi,
									   true));

	g.fillEllipse (baseHor - radi + 5 * (chanHor),
				   baseVer - radi + 5 * (chanVer),
				   radi * 2,
				   radi * 2);

    //[/UserPaint]
}

void SetupTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    speakerSelectBox->setBounds (32, 72, 160, 24);
    speakerPosXSlider->setBounds (232, 16, 150, 32);
    speakerPosYSlider->setBounds (232, 48, 150, 32);
    speakerPosZSlider->setBounds (232, 80, 150, 32);
    _1->setBounds (32, 16, 16, 16);
    _2->setBounds (64, 16, 16, 16);
    _3->setBounds (96, 16, 16, 16);
    _4->setBounds (128, 16, 16, 16);
    _5->setBounds (32, 40, 16, 16);
    _6->setBounds (64, 40, 16, 16);
    _7->setBounds (96, 40, 16, 16);
    _8->setBounds (128, 40, 16, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SetupTab::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == speakerSelectBox)
    {
        //[UserComboBoxCode_speakerSelectBox] -- add your combo box handling code here..
		Vector3D<float> speakerPos = processor.speakerSet[0]->getSpeakerPos(speakerSelectBox->getSelectedItemIndex());

		y = speakerPos.x;
		z = speakerPos.y;
		x = speakerPos.z;

		speakerPosXSlider->setValue(y, dontSendNotification);
		speakerPosYSlider->setValue(z, dontSendNotification);
		speakerPosZSlider->setValue(x, dontSendNotification);

        //[/UserComboBoxCode_speakerSelectBox]
    }

    //[UsercomboBoxChanged_Post]
	repaint();
    //[/UsercomboBoxChanged_Post]
}

void SetupTab::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == speakerPosXSlider)
    {
        //[UserSliderCode_speakerPosXSlider] -- add your slider handling code here..
		y = speakerPosXSlider->getValue();
		processor.setSpeakerPosX(speakerSelectBox->getSelectedItemIndex(),y);
        //[/UserSliderCode_speakerPosXSlider]
    }
    else if (sliderThatWasMoved == speakerPosYSlider)
    {
        //[UserSliderCode_speakerPosYSlider] -- add your slider handling code here..
		z = speakerPosYSlider->getValue();
		processor.setSpeakerPosY(speakerSelectBox->getSelectedItemIndex(),z);
        //[/UserSliderCode_speakerPosYSlider]
    }
    else if (sliderThatWasMoved == speakerPosZSlider)
    {
        //[UserSliderCode_speakerPosZSlider] -- add your slider handling code here..
		x = speakerPosZSlider->getValue();
		processor.setSpeakerPosZ(speakerSelectBox->getSelectedItemIndex(),x);
        //[/UserSliderCode_speakerPosZSlider]
    }

    //[UsersliderValueChanged_Post]
	repaint();
    //[/UsersliderValueChanged_Post]
}

void SetupTab::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
	Vector3D<float> pos;
	float gain;
	float delay;
	String name;
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == _1)
    {
        //[UserButtonCode__1] -- add your button handler code here..
		name = processor.speakerSet[0]->getSpeakerName(0);
		pos = processor.speakerSet[0]->getSpeakerPos(0);
		gain = processor.speakerSet[0]->getSpeakerGain(0);
		delay = processor.speakerSet[0]->getSpeakerDelay(0);
		speakerSelectBox->setSelectedItemIndex(0);
        //[/UserButtonCode__1]
    }
    else if (buttonThatWasClicked == _2)
    {
        //[UserButtonCode__2] -- add your button handler code here..
		name = processor.speakerSet[0]->getSpeakerName(1);
		pos = processor.speakerSet[0]->getSpeakerPos(1);
		gain = processor.speakerSet[0]->getSpeakerGain(1);
		delay = processor.speakerSet[0]->getSpeakerDelay(1);
		speakerSelectBox->setSelectedItemIndex(1);
        //[/UserButtonCode__2]
    }
    else if (buttonThatWasClicked == _3)
    {
        //[UserButtonCode__3] -- add your button handler code here..
		name = processor.speakerSet[0]->getSpeakerName(2);
		pos = processor.speakerSet[0]->getSpeakerPos(2);
		gain = processor.speakerSet[0]->getSpeakerGain(2);
		delay = processor.speakerSet[0]->getSpeakerDelay(2);
		speakerSelectBox->setSelectedItemIndex(2);
        //[/UserButtonCode__3]
    }
    else if (buttonThatWasClicked == _4)
    {
        //[UserButtonCode__4] -- add your button handler code here..
		name = processor.speakerSet[0]->getSpeakerName(3);
		pos = processor.speakerSet[0]->getSpeakerPos(3);
		gain = processor.speakerSet[0]->getSpeakerGain(3);
		delay = processor.speakerSet[0]->getSpeakerDelay(3);
		speakerSelectBox->setSelectedItemIndex(3);
        //[/UserButtonCode__4]
    }
    else if (buttonThatWasClicked == _5)
    {
        //[UserButtonCode__5] -- add your button handler code here..
		name = processor.speakerSet[0]->getSpeakerName(4);
		pos = processor.speakerSet[0]->getSpeakerPos(4);
		gain = processor.speakerSet[0]->getSpeakerGain(4);
		delay = processor.speakerSet[0]->getSpeakerDelay(4);
		speakerSelectBox->setSelectedItemIndex(4);
        //[/UserButtonCode__5]
    }
    else if (buttonThatWasClicked == _6)
    {
        //[UserButtonCode__6] -- add your button handler code here..
		name = processor.speakerSet[0]->getSpeakerName(5);
		pos = processor.speakerSet[0]->getSpeakerPos(5);
		gain = processor.speakerSet[0]->getSpeakerGain(5);
		delay = processor.speakerSet[0]->getSpeakerDelay(5);
		speakerSelectBox->setSelectedItemIndex(5);
        //[/UserButtonCode__6]
    }
    else if (buttonThatWasClicked == _7)
    {
        //[UserButtonCode__7] -- add your button handler code here..
		name = processor.speakerSet[0]->getSpeakerName(6);
		pos = processor.speakerSet[0]->getSpeakerPos(6);
		gain = processor.speakerSet[0]->getSpeakerGain(6);
		delay = processor.speakerSet[0]->getSpeakerDelay(6);
		speakerSelectBox->setSelectedItemIndex(6);
        //[/UserButtonCode__7]
    }
    else if (buttonThatWasClicked == _8)
    {
        //[UserButtonCode__8] -- add your button handler code here..
		name = processor.speakerSet[0]->getSpeakerName(7);
		pos = processor.speakerSet[0]->getSpeakerPos(7);
		gain = processor.speakerSet[0]->getSpeakerGain(7);
		delay = processor.speakerSet[0]->getSpeakerDelay(7);
		speakerSelectBox->setSelectedItemIndex(7);
        //[/UserButtonCode__8]
    }

    //[UserbuttonClicked_Post]
	DBG(name << " :" <<
		"\nPos: " << pos.x << ", " << pos.y << ", " << pos.z << ", " <<
		"\nGain: " << gain <<
		"\ndelay: " << delay);

	repaint();
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SetupTab" componentName=""
                 parentClasses="public Component" constructorParams="UltraPanAudioProcessor&amp; p"
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="600"
                 initialHeight="120">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="-9 -3 617 131" fill="linear: 304 120, 304 0, 0=ff71c100, 1=ff4b8100"
          hasStroke="0"/>
  </BACKGROUND>
  <COMBOBOX name="new combo box" id="8c25a223e42a10e9" memberName="speakerSelectBox"
            virtualName="" explicitFocusOrder="0" pos="32 72 160 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="Speaker Pos X Slider" id="526e698b8aafaba8" memberName="speakerPosXSlider"
          virtualName="" explicitFocusOrder="0" pos="232 16 150 32" textboxbkgd="ffffff"
          min="-10" max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Speaker Pos Y Slider" id="f5f1383c17b825d8" memberName="speakerPosYSlider"
          virtualName="" explicitFocusOrder="0" pos="232 48 150 32" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Speaker Pos Z Slider" id="59946b0c986852eb" memberName="speakerPosZSlider"
          virtualName="" explicitFocusOrder="0" pos="232 80 150 32" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <TEXTBUTTON name="new button" id="d587cfd911f8a8ed" memberName="_1" virtualName=""
              explicitFocusOrder="0" pos="32 16 16 16" buttonText="1" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="b1af06007060d181" memberName="_2" virtualName=""
              explicitFocusOrder="0" pos="64 16 16 16" buttonText="2" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="731adc87d8f87c20" memberName="_3" virtualName=""
              explicitFocusOrder="0" pos="96 16 16 16" buttonText="3" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="b4932f066417545d" memberName="_4" virtualName=""
              explicitFocusOrder="0" pos="128 16 16 16" buttonText="4" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="414ce8d3059ae8a3" memberName="_5" virtualName=""
              explicitFocusOrder="0" pos="32 40 16 16" buttonText="5" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="e6dfba3e4c9a7b69" memberName="_6" virtualName=""
              explicitFocusOrder="0" pos="64 40 16 16" buttonText="6" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="314e45f55bda2ec7" memberName="_7" virtualName=""
              explicitFocusOrder="0" pos="96 40 16 16" buttonText="7" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="399940aa700cd54c" memberName="_8" virtualName=""
              explicitFocusOrder="0" pos="128 40 16 16" buttonText="8" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
