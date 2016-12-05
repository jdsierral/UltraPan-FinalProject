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

    addAndMakeVisible (speakerSelectBox = new ComboBox ("speakerSelectBox"));
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


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 120);


    //[Constructor] You can add your own custom stuff here..
	const int outs = processor.getTotalNumOutputChannels();
	for (int sp = 0; sp < outs;){
		sp++;
		speakerSelectBox->addItem("Speaker: " + String(sp), sp);
	}
	speakerSelectBox->setSelectedItemIndex(0);
	
	for (int out = 0; out < outs; out++) {
		speaker.setBases(450, 50);
		speaker.setMaxAndMinValues(sliderRange,
								   -sliderRange,
								   sliderRange,
								   -sliderRange,
								   sliderRange,
								   -sliderRange);
		speaker.setRadius(15);
		speaker.setColour(Colour (0xff0049a5));
	}
	
	update();
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

	speaker.drawCoordSphere(g, speakerPos.x, speakerPos.y, speakerPos.z);

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
		update();
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
		speakerPos.x = sliderThatWasMoved->getValue();
		processor.setSpeakerPosX(speakerSelectBox->getSelectedItemIndex(),speakerPos.x);
        //[/UserSliderCode_speakerPosXSlider]
    }
    else if (sliderThatWasMoved == speakerPosYSlider)
    {
        //[UserSliderCode_speakerPosYSlider] -- add your slider handling code here..
		speakerPos.y = sliderThatWasMoved->getValue();
		processor.setSpeakerPosY(speakerSelectBox->getSelectedItemIndex(),speakerPos.y);
        //[/UserSliderCode_speakerPosYSlider]
    }
    else if (sliderThatWasMoved == speakerPosZSlider)
    {
        //[UserSliderCode_speakerPosZSlider] -- add your slider handling code here..
		speakerPos.z = sliderThatWasMoved->getValue();
		processor.setSpeakerPosZ(speakerSelectBox->getSelectedItemIndex(),speakerPos.z);
        //[/UserSliderCode_speakerPosZSlider]
    }

    //[UsersliderValueChanged_Post]
	repaint();
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void SetupTab::update() {
	speakerPos = processor.getSpeakerPos(speakerSelectBox->getSelectedItemIndex());
	
	speakerPosXSlider->setValue(speakerPos.x, dontSendNotification);
	speakerPosYSlider->setValue(speakerPos.y, dontSendNotification);
	speakerPosZSlider->setValue(speakerPos.z, dontSendNotification);
}

void SetupTab::updateNumChannels(int ins, int outs) {
	int numItems = speakerSelectBox->getNumItems();
	
	if (outs > numItems) {
		for (int sp = numItems; sp < outs;){
			sp++;
			speakerSelectBox->addItem("Speaker: " + String(sp), sp);
		}
	} else {
		while (outs < numItems) {
			numItems--;
			int id = speakerSelectBox->getItemId(numItems);
			speakerSelectBox->setItemEnabled(id, false);
		}
	}
	
	speakerSelectBox->setSelectedItemIndex(0);
	
	for (int out = 0; out < outs; out++) {
		speaker.setBases(450, 50);
		speaker.setMaxAndMinValues(sliderRange,
								   -sliderRange,
								   sliderRange,
								   -sliderRange,
								   sliderRange,
								   -sliderRange);
		speaker.setRadius(15);
		speaker.setColour(Colour (0xff0049a5));
	}
	
}
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
  <COMBOBOX name="speakerSelectBox" id="8c25a223e42a10e9" memberName="speakerSelectBox"
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
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
