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

    addAndMakeVisible (speakerPosXSlider = new Slider ("speakerPosXSlider"));
    speakerPosXSlider->setRange (-10, 10, 0);
    speakerPosXSlider->setSliderStyle (Slider::LinearHorizontal);
    speakerPosXSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    speakerPosXSlider->addListener (this);

    addAndMakeVisible (speakerPosYSlider = new Slider ("speakerPosYSlider"));
    speakerPosYSlider->setRange (-10, 10, 0);
    speakerPosYSlider->setSliderStyle (Slider::LinearHorizontal);
    speakerPosYSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    speakerPosYSlider->addListener (this);

    addAndMakeVisible (speakerPosZSlider = new Slider ("speakerPosZSlider"));
    speakerPosZSlider->setRange (-10, 10, 0);
    speakerPosZSlider->setSliderStyle (Slider::LinearHorizontal);
    speakerPosZSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    speakerPosZSlider->addListener (this);

    addAndMakeVisible (speakerPosXLabel = new Label ("speakerPosXLabel",
                                                     TRANS("Base")));
    speakerPosXLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    speakerPosXLabel->setJustificationType (Justification::centredLeft);
    speakerPosXLabel->setEditable (true, true, false);
    speakerPosXLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    speakerPosXLabel->setColour (TextEditor::textColourId, Colours::black);
    speakerPosXLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    speakerPosXLabel->addListener (this);

    addAndMakeVisible (speakerPosYLabel = new Label ("speakerPosYLabel",
                                                     TRANS("Base")));
    speakerPosYLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    speakerPosYLabel->setJustificationType (Justification::centredLeft);
    speakerPosYLabel->setEditable (true, true, false);
    speakerPosYLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    speakerPosYLabel->setColour (TextEditor::textColourId, Colours::black);
    speakerPosYLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    speakerPosYLabel->addListener (this);

    addAndMakeVisible (speakerPosZLabel = new Label ("speakerPosZLabel",
                                                     TRANS("Base")));
    speakerPosZLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    speakerPosZLabel->setJustificationType (Justification::centredLeft);
    speakerPosZLabel->setEditable (true, true, false);
    speakerPosZLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    speakerPosZLabel->setColour (TextEditor::textColourId, Colours::black);
    speakerPosZLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    speakerPosZLabel->addListener (this);

    cachedImage_setupTab_png_1 = ImageCache::getFromMemory (setupTab_png, setupTab_pngSize);

    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 300);


    //[Constructor] You can add your own custom stuff here..
	const int outs = processor.getTotalNumOutputChannels();
	for (int sp = 0; sp < outs;){
		sp++;
		speakerSelectBox->addItem("Speaker: " + String(sp), sp);
	}
	speakerSelectBox->setSelectedItemIndex(0);

	for (int out = 0; out < outs; out++) {
		speaker.setBases(100, 230);
		speaker.setScale(0.8, 0.8);
		speaker.setMaxAndMinValues(sliderRange,
								   -sliderRange,
								   sliderRange,
								   -sliderRange,
								   sliderRange,
								   -sliderRange);
		speaker.setRadius(15);
		speaker.setColour(Colour (0xff00BCD1));
	}
	
	speakerPosXSlider->addMouseListener(this, false);
	speakerPosYSlider->addMouseListener(this, false);
	speakerPosZSlider->addMouseListener(this, false);

	speakerPosXLabel->setText("x", dontSendNotification);
	speakerPosYLabel->setText("y", dontSendNotification);
	speakerPosZLabel->setText("z", dontSendNotification);

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
    speakerPosXLabel = nullptr;
    speakerPosYLabel = nullptr;
    speakerPosZLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SetupTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff303030));

    g.setColour (Colours::black);
    g.drawImageWithin (cachedImage_setupTab_png_1,
                       -14, 6, 225, 300,
                       RectanglePlacement::centred | RectanglePlacement::onlyReduceInSize,
                       false);

    //[UserPaint] Add your own custom painting code here..

	speaker.drawCoordSphere(g, speakerPos.x, speakerPos.y, speakerPos.z);

    //[/UserPaint]
}

void SetupTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    speakerSelectBox->setBounds (27, 144, 145, 15);
    speakerPosXSlider->setBounds (44, 36, 150, 16);
    speakerPosYSlider->setBounds (44, 68, 150, 16);
    speakerPosZSlider->setBounds (44, 100, 150, 16);
    speakerPosXLabel->setBounds (4, 36, 40, 16);
    speakerPosYLabel->setBounds (4, 68, 40, 16);
    speakerPosZLabel->setBounds (4, 100, 40, 16);
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
		speakerPosXLabel->setText(String(speakerPosXSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_speakerPosXSlider]
    }
    else if (sliderThatWasMoved == speakerPosYSlider)
    {
        //[UserSliderCode_speakerPosYSlider] -- add your slider handling code here..
		speakerPos.y = sliderThatWasMoved->getValue();
		processor.setSpeakerPosY(speakerSelectBox->getSelectedItemIndex(),speakerPos.y);
		speakerPosYLabel->setText(String(speakerPosYSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_speakerPosYSlider]
    }
    else if (sliderThatWasMoved == speakerPosZSlider)
    {
        //[UserSliderCode_speakerPosZSlider] -- add your slider handling code here..
		speakerPos.z = sliderThatWasMoved->getValue();
		processor.setSpeakerPosZ(speakerSelectBox->getSelectedItemIndex(),speakerPos.z);
		speakerPosZLabel->setText(String(speakerPosZSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_speakerPosZSlider]
    }

    //[UsersliderValueChanged_Post]
	repaint();
    //[/UsersliderValueChanged_Post]
}

void SetupTab::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == speakerPosXLabel)
    {
        //[UserLabelCode_speakerPosXLabel] -- add your label text handling code here..
		speakerPosXSlider->setValue(labelThatHasChanged->getText().getFloatValue());
        //[/UserLabelCode_speakerPosXLabel]
    }
    else if (labelThatHasChanged == speakerPosYLabel)
    {
        //[UserLabelCode_speakerPosYLabel] -- add your label text handling code here..
		speakerPosYSlider->setValue(labelThatHasChanged->getText().getFloatValue());
        //[/UserLabelCode_speakerPosYLabel]
    }
    else if (labelThatHasChanged == speakerPosZLabel)
    {
        //[UserLabelCode_speakerPosZLabel] -- add your label text handling code here..
		speakerPosZSlider->setValue(labelThatHasChanged->getText().getFloatValue());
        //[/UserLabelCode_speakerPosZLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
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

void SetupTab::mouseEnter(const MouseEvent& e) {
	if (e.eventComponent == speakerPosXSlider) {
		speakerPosXLabel->setText(String(speakerPosXSlider->getValue(), 1), dontSendNotification);
	}
	if (e.eventComponent == speakerPosYSlider) {
		speakerPosYLabel->setText(String(speakerPosYSlider->getValue(), 1), dontSendNotification);
	}
	if (e.eventComponent == speakerPosZSlider) {
		speakerPosZLabel->setText(String(speakerPosZSlider->getValue(), 1), dontSendNotification);
	}
	
}

void SetupTab::mouseExit(const MouseEvent& e) {
	
	if (e.eventComponent == speakerPosXSlider) {
		speakerPosXLabel->setText("x", dontSendNotification);
	}
	if (e.eventComponent == speakerPosYSlider) {
		speakerPosYLabel->setText("y", dontSendNotification);
	}
	if (e.eventComponent == speakerPosZSlider) {
		speakerPosZLabel->setText("z", dontSendNotification);
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
                 variableInitialisers="processor(p)" snapPixels="8" snapActive="0"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="200"
                 initialHeight="300">
  <BACKGROUND backgroundColour="ff303030">
    <IMAGE pos="-14 6 225 300" resource="setupTab_png" opacity="1" mode="2"/>
  </BACKGROUND>
  <COMBOBOX name="speakerSelectBox" id="8c25a223e42a10e9" memberName="speakerSelectBox"
            virtualName="" explicitFocusOrder="0" pos="27 144 145 15" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="speakerPosXSlider" id="11759a50dc05a4c4" memberName="speakerPosXSlider"
          virtualName="" explicitFocusOrder="0" pos="44 36 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="speakerPosYSlider" id="3c232841636fc9d1" memberName="speakerPosYSlider"
          virtualName="" explicitFocusOrder="0" pos="44 68 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="speakerPosZSlider" id="8cc1089f0229ede7" memberName="speakerPosZSlider"
          virtualName="" explicitFocusOrder="0" pos="44 100 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="speakerPosXLabel" id="8d40430beb9cafbb" memberName="speakerPosXLabel"
         virtualName="" explicitFocusOrder="0" pos="4 36 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="speakerPosYLabel" id="80990c70efbda5e5" memberName="speakerPosYLabel"
         virtualName="" explicitFocusOrder="0" pos="4 68 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="speakerPosZLabel" id="9deec04ec5fb5ccb" memberName="speakerPosZLabel"
         virtualName="" explicitFocusOrder="0" pos="4 100 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//==============================================================================
// Binary resources - be careful not to edit any of these sections!

// JUCER_RESOURCE: setupTab_png, 1202, "../Resources/SetupTab.png"
static const unsigned char resource_SetupTab_setupTab_png[] = { 137,80,78,71,13,10,26,10,0,0,0,13,73,72,68,82,0,0,0,202,0,0,1,46,8,6,0,0,0,207,199,141,136,0,0,0,9,112,72,89,115,0,0,11,18,0,0,11,18,1,210,
221,126,252,0,0,4,100,73,68,65,84,120,218,237,219,77,114,234,70,20,128,209,219,66,66,162,16,127,246,70,188,255,21,81,30,24,92,20,152,162,65,202,32,149,65,38,121,201,3,3,145,207,217,128,132,187,191,106,
93,129,211,219,219,91,31,192,63,42,252,9,64,40,32,20,16,10,8,5,132,2,66,1,161,0,66,1,161,128,80,64,40,32,20,16,10,8,5,16,10,8,5,132,2,66,1,161,128,80,64,40,32,20,64,40,32,20,16,10,8,5,132,2,66,1,161,0,
66,1,161,128,80,64,40,32,20,16,10,8,5,16,10,8,5,132,2,66,1,161,128,80,64,40,32,20,64,40,32,20,16,10,8,5,132,2,66,1,161,0,66,1,161,128,80,64,40,32,20,16,10,8,5,16,10,8,5,132,2,66,1,161,128,80,64,40,32,
20,64,40,32,20,16,10,8,5,132,2,66,1,161,0,66,1,161,128,80,64,40,32,20,16,10,8,5,132,2,8,5,132,2,66,1,161,128,80,64,40,32,20,64,40,32,20,16,10,8,5,132,2,66,1,161,0,66,1,161,128,80,64,40,32,20,16,10,8,5,
132,2,8,5,132,2,66,1,161,128,80,64,40,32,20,64,40,32,20,16,10,8,5,132,2,66,1,161,0,66,1,161,128,80,64,40,32,20,16,10,8,5,132,2,8,5,132,2,66,1,161,128,80,64,40,32,20,64,40,32,20,16,10,8,5,132,2,66,1,161,
128,80,0,161,128,80,64,40,32,20,16,10,8,5,132,2,8,5,132,2,66,1,161,128,80,64,40,32,20,64,40,32,20,16,10,8,5,132,2,66,1,161,192,15,86,62,250,6,114,206,177,223,239,227,120,60,70,215,117,145,82,138,178,44,
173,204,15,117,62,159,163,239,251,40,138,34,154,166,137,233,116,26,85,85,253,220,80,114,206,177,217,108,34,231,28,117,93,199,100,50,137,162,112,192,241,167,174,235,34,231,28,239,239,239,81,85,85,172,86,
171,135,6,243,144,157,185,219,237,98,189,94,71,74,41,230,243,121,212,117,45,18,254,190,49,139,34,234,186,142,249,124,30,41,165,88,175,215,177,219,237,126,206,137,242,241,241,17,135,195,33,102,179,89,140,
70,35,59,130,95,106,154,38,170,170,138,207,207,207,200,57,199,203,203,203,176,79,148,221,110,23,135,195,33,218,182,21,9,255,201,104,52,138,182,109,227,112,56,60,228,100,185,91,40,57,231,216,110,183,49,
157,78,69,194,111,199,50,157,78,99,187,221,70,206,121,152,161,108,54,155,104,154,198,27,45,174,155,21,202,50,154,166,137,205,102,51,188,80,114,206,113,58,157,162,174,107,43,205,213,234,186,142,211,233,
116,215,83,229,46,161,236,247,251,24,143,199,145,82,178,202,92,45,165,20,227,241,56,246,251,253,176,66,57,30,143,79,241,165,17,195,81,85,85,28,143,199,225,61,122,153,77,184,245,172,50,184,71,47,111,185,
248,174,125,213,117,221,112,66,49,155,240,93,251,106,80,161,192,119,62,130,9,5,158,132,80,64,40,32,20,16,10,8,5,132,2,66,1,161,0,66,1,161,128,80,64,40,32,20,16,10,8,5,16,10,8,5,132,2,66,1,161,128,80,64,
40,32,20,64,40,32,20,16,10,8,5,132,2,66,1,161,0,66,1,161,128,80,64,40,32,20,16,10,8,5,16,10,8,5,132,2,66,1,161,128,80,64,40,32,20,64,40,32,20,16,10,8,5,132,2,66,1,161,0,66,1,161,128,80,64,40,32,20,16,
10,8,5,16,10,8,5,132,2,66,1,161,128,80,64,40,32,20,64,40,32,20,16,10,8,5,132,2,66,1,161,0,66,1,161,128,80,64,40,32,20,16,10,8,5,132,2,8,5,132,2,66,1,161,128,80,64,40,32,20,64,40,32,20,16,10,8,5,132,2,
66,1,161,0,119,12,165,40,244,200,255,123,95,221,229,74,85,85,69,223,247,86,150,155,233,251,62,170,170,26,86,40,147,201,36,114,206,86,151,155,201,57,199,100,50,25,94,40,93,215,89,93,110,166,235,186,225,
133,18,17,209,182,109,92,46,23,43,204,213,46,151,75,180,109,59,188,97,254,175,83,197,156,194,173,230,147,123,158,38,119,13,37,34,98,181,90,153,85,184,122,54,89,173,86,119,191,238,221,223,219,46,151,75,
243,10,191,61,151,44,151,203,135,92,251,238,161,20,69,17,139,197,34,82,74,86,158,127,45,165,20,139,197,226,97,223,201,149,143,250,224,109,219,198,249,124,142,175,175,47,187,128,95,206,183,101,89,62,244,
30,30,122,245,178,44,99,54,155,69,215,117,113,58,157,226,124,62,27,248,137,148,82,148,101,25,227,241,248,105,126,213,81,62,195,77,20,69,17,77,211,216,33,60,45,63,194,2,161,128,80,64,40,32,20,16,10,8,5,
132,2,8,5,132,2,66,1,161,128,80,64,40,240,83,164,215,215,87,255,0,2,78,20,184,222,31,86,185,192,93,199,99,68,211,0,0,0,0,73,69,78,68,174,66,96,130,0,0};

const char* SetupTab::setupTab_png = (const char*) resource_SetupTab_setupTab_png;
const int SetupTab::setupTab_pngSize = 1202;


//[EndFile] You can add extra defines here...
//[/EndFile]
