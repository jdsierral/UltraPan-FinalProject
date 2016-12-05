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
    mainVolSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    mainVolSlider->addListener (this);

    addAndMakeVisible (baseSlider = new Slider ("Base Slider"));
    baseSlider->setRange (1, 1000, 0);
    baseSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    baseSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    baseSlider->addListener (this);

    addAndMakeVisible (pos1XSlider = new Slider ("pos1XSlider"));
    pos1XSlider->setRange (-10, 10, 0);
    pos1XSlider->setSliderStyle (Slider::LinearHorizontal);
    pos1XSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pos1XSlider->addListener (this);

    addAndMakeVisible (pos1YSlider = new Slider ("pos1YSlider"));
    pos1YSlider->setRange (-10, 10, 0);
    pos1YSlider->setSliderStyle (Slider::LinearHorizontal);
    pos1YSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pos1YSlider->addListener (this);

    addAndMakeVisible (pos1ZSlider = new Slider ("pos1ZSlider"));
    pos1ZSlider->setRange (-10, 10, 0);
    pos1ZSlider->setSliderStyle (Slider::LinearHorizontal);
    pos1ZSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pos1ZSlider->addListener (this);

    addAndMakeVisible (pos2XSlider = new Slider ("pos2XSlider"));
    pos2XSlider->setRange (-10, 10, -10);
    pos2XSlider->setSliderStyle (Slider::LinearHorizontal);
    pos2XSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pos2XSlider->addListener (this);

    addAndMakeVisible (pos2YSlider = new Slider ("pos2YSlider"));
    pos2YSlider->setRange (-10, 10, 0);
    pos2YSlider->setSliderStyle (Slider::LinearHorizontal);
    pos2YSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pos2YSlider->addListener (this);

    addAndMakeVisible (pos2ZSlider = new Slider ("pos2ZSlider"));
    pos2ZSlider->setRange (-10, 10, 0);
    pos2ZSlider->setSliderStyle (Slider::LinearHorizontal);
    pos2ZSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pos2ZSlider->addListener (this);

    addAndMakeVisible (mainVolLabel = new Label ("mainVolLabel",
                                                 TRANS("Vol")));
    mainVolLabel->setFont (Font ("Futura-Light", 22.00f, Font::plain));
    mainVolLabel->setJustificationType (Justification::centredLeft);
    mainVolLabel->setEditable (true, true, false);
    mainVolLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    mainVolLabel->setColour (TextEditor::textColourId, Colours::black);
    mainVolLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    mainVolLabel->addListener (this);

    addAndMakeVisible (baseLabel = new Label ("baseLabel",
                                              TRANS("Base")));
    baseLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    baseLabel->setJustificationType (Justification::centredLeft);
    baseLabel->setEditable (true, true, false);
    baseLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    baseLabel->setColour (TextEditor::textColourId, Colours::black);
    baseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    baseLabel->addListener (this);

    addAndMakeVisible (pos1XLabel = new Label ("pos1XLabel",
                                               TRANS("Base")));
    pos1XLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    pos1XLabel->setJustificationType (Justification::centredLeft);
    pos1XLabel->setEditable (true, true, false);
    pos1XLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    pos1XLabel->setColour (TextEditor::textColourId, Colours::black);
    pos1XLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    pos1XLabel->addListener (this);

    addAndMakeVisible (pos1YLabel = new Label ("pos1YLabel",
                                               TRANS("Base")));
    pos1YLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    pos1YLabel->setJustificationType (Justification::centredLeft);
    pos1YLabel->setEditable (true, true, false);
    pos1YLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    pos1YLabel->setColour (TextEditor::textColourId, Colours::black);
    pos1YLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    pos1YLabel->addListener (this);

    addAndMakeVisible (pos1ZLabel = new Label ("pos1ZLabel",
                                               TRANS("Base")));
    pos1ZLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    pos1ZLabel->setJustificationType (Justification::centredLeft);
    pos1ZLabel->setEditable (true, true, false);
    pos1ZLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    pos1ZLabel->setColour (TextEditor::textColourId, Colours::black);
    pos1ZLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    pos1ZLabel->addListener (this);

    addAndMakeVisible (pos2XLabel = new Label ("pos2XLabel",
                                               TRANS("Base")));
    pos2XLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    pos2XLabel->setJustificationType (Justification::centredLeft);
    pos2XLabel->setEditable (true, true, false);
    pos2XLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    pos2XLabel->setColour (TextEditor::textColourId, Colours::black);
    pos2XLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    pos2XLabel->addListener (this);

    addAndMakeVisible (pos2YLabel = new Label ("pos2YLabel",
                                               TRANS("Base")));
    pos2YLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    pos2YLabel->setJustificationType (Justification::centredLeft);
    pos2YLabel->setEditable (true, true, false);
    pos2YLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    pos2YLabel->setColour (TextEditor::textColourId, Colours::black);
    pos2YLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    pos2YLabel->addListener (this);

    addAndMakeVisible (pos2ZLabel = new Label ("pos2ZLabel",
                                               TRANS("Base")));
    pos2ZLabel->setFont (Font ("Futura-Light", 14.00f, Font::plain));
    pos2ZLabel->setJustificationType (Justification::centredLeft);
    pos2ZLabel->setEditable (true, true, false);
    pos2ZLabel->setColour (Label::textColourId, Colour (0xfff4efe7));
    pos2ZLabel->setColour (TextEditor::textColourId, Colours::black);
    pos2ZLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    pos2ZLabel->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 300);


    //[Constructor] You can add your own custom stuff here..
	pos1XSlider->addMouseListener(this, false);
	pos1YSlider->addMouseListener(this, false);
	pos1ZSlider->addMouseListener(this, false);
	
	pos2XSlider->addMouseListener(this, false);
	pos2YSlider->addMouseListener(this, false);
	pos2ZSlider->addMouseListener(this, false);
	
	mainVolSlider->addMouseListener(this, false);
	baseSlider->addMouseListener(this, false);
	
	mainVolLabel->setText("Main Vol", dontSendNotification);
	baseLabel->setText("Base", dontSendNotification);
	pos1XLabel->setText("Left x", dontSendNotification);
	pos1YLabel->setText("Left y", dontSendNotification);
	pos1ZLabel->setText("Left z", dontSendNotification);
	pos2XLabel->setText("Right x", dontSendNotification);
	pos2YLabel->setText("Right y", dontSendNotification);
	pos2ZLabel->setText("Right z", dontSendNotification);
	
    //[/Constructor]
}

MainTab::~MainTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    mainVolSlider = nullptr;
    baseSlider = nullptr;
    pos1XSlider = nullptr;
    pos1YSlider = nullptr;
    pos1ZSlider = nullptr;
    pos2XSlider = nullptr;
    pos2YSlider = nullptr;
    pos2ZSlider = nullptr;
    mainVolLabel = nullptr;
    baseLabel = nullptr;
    pos1XLabel = nullptr;
    pos1YLabel = nullptr;
    pos1ZLabel = nullptr;
    pos2XLabel = nullptr;
    pos2YLabel = nullptr;
    pos2ZLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainTab::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff303030));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mainVolSlider->setBounds (32, 112, 72, 80);
    baseSlider->setBounds (120, 168, 32, 24);
    pos1XSlider->setBounds (48, 24, 150, 16);
    pos1YSlider->setBounds (48, 56, 150, 16);
    pos1ZSlider->setBounds (48, 88, 150, 16);
    pos2XSlider->setBounds (48, 200, 150, 16);
    pos2YSlider->setBounds (48, 232, 150, 16);
    pos2ZSlider->setBounds (48, 264, 150, 16);
    mainVolLabel->setBounds (112, 120, 88, 24);
    baseLabel->setBounds (152, 176, 40, 16);
    pos1XLabel->setBounds (8, 24, 40, 16);
    pos1YLabel->setBounds (8, 56, 40, 16);
    pos1ZLabel->setBounds (8, 88, 40, 16);
    pos2XLabel->setBounds (8, 200, 40, 16);
    pos2YLabel->setBounds (8, 232, 40, 16);
    pos2ZLabel->setBounds (8, 264, 40, 16);
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
		mainVolLabel->setText(String(mainVolSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_mainVolSlider]
    }
    else if (sliderThatWasMoved == baseSlider)
    {
        //[UserSliderCode_baseSlider] -- add your slider handling code here..
		*processor.base = baseSlider->getValue();
		baseLabel->setText(String(baseSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_baseSlider]
    }
    else if (sliderThatWasMoved == pos1XSlider)
    {
        //[UserSliderCode_pos1XSlider] -- add your slider handling code here..
		*processor.pos1X = sliderThatWasMoved->getValue();
		pos1XLabel->setText(String(pos1XSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_pos1XSlider]
    }
    else if (sliderThatWasMoved == pos1YSlider)
    {
        //[UserSliderCode_pos1YSlider] -- add your slider handling code here..
		*processor.pos1Y = sliderThatWasMoved->getValue();
		pos1YLabel->setText(String(pos1YSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_pos1YSlider]
    }
    else if (sliderThatWasMoved == pos1ZSlider)
    {
        //[UserSliderCode_pos1ZSlider] -- add your slider handling code here..
		*processor.pos1Z = sliderThatWasMoved->getValue();
		pos1ZLabel->setText(String(pos1ZSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_pos1ZSlider]
    }
    else if (sliderThatWasMoved == pos2XSlider)
    {
        //[UserSliderCode_pos2XSlider] -- add your slider handling code here..
		*processor.pos2X = sliderThatWasMoved->getValue();
		pos2XLabel->setText(String(pos2XSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_pos2XSlider]
    }
    else if (sliderThatWasMoved == pos2YSlider)
    {
        //[UserSliderCode_pos2YSlider] -- add your slider handling code here..
		*processor.pos2Y = sliderThatWasMoved->getValue();
		pos2YLabel->setText(String(pos2YSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_pos2YSlider]
    }
    else if (sliderThatWasMoved == pos2ZSlider)
    {
        //[UserSliderCode_pos2ZSlider] -- add your slider handling code here..
		*processor.pos2Z = sliderThatWasMoved->getValue();
		pos2ZLabel->setText(String(pos2ZSlider->getValue(), 1), dontSendNotification);
        //[/UserSliderCode_pos2ZSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MainTab::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == mainVolLabel)
    {
        //[UserLabelCode_mainVolLabel] -- add your label text handling code here..
		mainVolSlider->setValue(mainVolLabel->getText().getFloatValue());
        //[/UserLabelCode_mainVolLabel]
    }
    else if (labelThatHasChanged == baseLabel)
    {
        //[UserLabelCode_baseLabel] -- add your label text handling code here..
		baseSlider->setValue(baseLabel->getText().getFloatValue());
        //[/UserLabelCode_baseLabel]
    }
    else if (labelThatHasChanged == pos1XLabel)
    {
        //[UserLabelCode_pos1XLabel] -- add your label text handling code here..
		pos1XSlider->setValue(pos1XLabel->getText().getFloatValue());
        //[/UserLabelCode_pos1XLabel]
    }
    else if (labelThatHasChanged == pos1YLabel)
    {
        //[UserLabelCode_pos1YLabel] -- add your label text handling code here..
		pos1YSlider->setValue(pos1YLabel->getText().getFloatValue());
        //[/UserLabelCode_pos1YLabel]
    }
    else if (labelThatHasChanged == pos1ZLabel)
    {
        //[UserLabelCode_pos1ZLabel] -- add your label text handling code here..
		pos1ZSlider->setValue(pos1ZLabel->getText().getFloatValue());
        //[/UserLabelCode_pos1ZLabel]
    }
    else if (labelThatHasChanged == pos2XLabel)
    {
        //[UserLabelCode_pos2XLabel] -- add your label text handling code here..
		pos2XSlider->setValue(pos2XLabel->getText().getFloatValue());
        //[/UserLabelCode_pos2XLabel]
    }
    else if (labelThatHasChanged == pos2YLabel)
    {
        //[UserLabelCode_pos2YLabel] -- add your label text handling code here..
		pos2YSlider->setValue(pos2YLabel->getText().getFloatValue());
        //[/UserLabelCode_pos2YLabel]
    }
    else if (labelThatHasChanged == pos2ZLabel)
    {
        //[UserLabelCode_pos2ZLabel] -- add your label text handling code here..
		pos2ZSlider->setValue(pos2ZLabel->getText().getFloatValue());
        //[/UserLabelCode_pos2ZLabel]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainTab::update() {

	l = Vector3D<float>(*processor.pos1X, *processor.pos1Y, *processor.pos1Z);
	r = Vector3D<float>(*processor.pos2X, *processor.pos2Y, *processor.pos2Z);

	pos1XSlider->setValue(l.x, dontSendNotification);
	pos1YSlider->setValue(l.y, dontSendNotification);
	pos1ZSlider->setValue(l.z, dontSendNotification);

	pos2XSlider->setValue(r.x, dontSendNotification);
	pos2YSlider->setValue(r.y, dontSendNotification);
	pos2ZSlider->setValue(r.z, dontSendNotification);
}

void MainTab::updateNumChannels(int ins, int outs) {

}

void MainTab::mouseEnter(const MouseEvent& e) {
	if (e.eventComponent == mainVolSlider) {
		mainVolLabel->setText(String(mainVolSlider->getValue(), 1), dontSendNotification);
	}
	if (e.eventComponent == baseSlider) {
		baseLabel->setText(String(baseSlider->getValue(), 1), dontSendNotification);
	}
	if (e.eventComponent == pos1XSlider) {
		pos1XLabel->setText(String(pos1XSlider->getValue(), 1), dontSendNotification);
	}
	if (e.eventComponent == pos1YSlider) {
		pos1YLabel->setText(String(pos1YSlider->getValue(), 1), dontSendNotification);
	}
	if (e.eventComponent == pos1ZSlider) {
		pos1ZLabel->setText(String(pos1ZSlider->getValue(), 1), dontSendNotification);
	}
	if (e.eventComponent == pos2XSlider) {
		pos2XLabel->setText(String(pos2XSlider->getValue(), 1), dontSendNotification);
	}
	if (e.eventComponent == pos2YSlider) {
		pos2YLabel->setText(String(pos2YSlider->getValue(), 1), dontSendNotification);
	}
	if (e.eventComponent == pos2ZSlider) {
		pos2ZLabel->setText(String(pos2ZSlider->getValue(), 1), dontSendNotification);
	}
	
}

void MainTab::mouseExit(const MouseEvent& e) {
	if (e.eventComponent == mainVolSlider) {
		mainVolLabel->setText("Main Vol", dontSendNotification);
	}
	if (e.eventComponent == baseSlider) {
		baseLabel->setText("Base", dontSendNotification);
	}
	if (e.eventComponent == pos1XSlider) {
		pos1XLabel->setText("Left x", dontSendNotification);
	}
	if (e.eventComponent == pos1YSlider) {
		pos1YLabel->setText("Left y", dontSendNotification);
	}
	if (e.eventComponent == pos1ZSlider) {
		pos1ZLabel->setText("Left z", dontSendNotification);
	}
	if (e.eventComponent == pos2XSlider) {
		pos2XLabel->setText("Right x", dontSendNotification);
	}
	if (e.eventComponent == pos2YSlider) {
		pos2YLabel->setText("Right y", dontSendNotification);
	}
	if (e.eventComponent == pos2ZSlider) {
		pos2ZLabel->setText("Right z", dontSendNotification);
	}
}

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
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="200"
                 initialHeight="300">
  <BACKGROUND backgroundColour="ff303030"/>
  <SLIDER name="Main Volume Slider" id="48e517a99b24c0fe" memberName="mainVolSlider"
          virtualName="" explicitFocusOrder="0" pos="32 112 72 80" min="-60"
          max="12" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Base Slider" id="271c0bce09620c47" memberName="baseSlider"
          virtualName="" explicitFocusOrder="0" pos="120 168 32 24" min="1"
          max="1000" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos1XSlider" id="11759a50dc05a4c4" memberName="pos1XSlider"
          virtualName="" explicitFocusOrder="0" pos="48 24 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos1YSlider" id="3c232841636fc9d1" memberName="pos1YSlider"
          virtualName="" explicitFocusOrder="0" pos="48 56 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos1ZSlider" id="8cc1089f0229ede7" memberName="pos1ZSlider"
          virtualName="" explicitFocusOrder="0" pos="48 88 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos2XSlider" id="b46e098975ec1c6a" memberName="pos2XSlider"
          virtualName="" explicitFocusOrder="0" pos="48 200 150 16" min="-10"
          max="10" int="-10" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos2YSlider" id="7cd99f02df05bb9c" memberName="pos2YSlider"
          virtualName="" explicitFocusOrder="0" pos="48 232 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos2ZSlider" id="40bcc69e2e0325a6" memberName="pos2ZSlider"
          virtualName="" explicitFocusOrder="0" pos="48 264 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <LABEL name="mainVolLabel" id="e7b2029080ddf62d" memberName="mainVolLabel"
         virtualName="" explicitFocusOrder="0" pos="112 120 88 24" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Vol" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="22" bold="0" italic="0" justification="33"/>
  <LABEL name="baseLabel" id="879160405914be45" memberName="baseLabel"
         virtualName="" explicitFocusOrder="0" pos="152 176 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="pos1XLabel" id="8d40430beb9cafbb" memberName="pos1XLabel"
         virtualName="" explicitFocusOrder="0" pos="8 24 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="pos1YLabel" id="80990c70efbda5e5" memberName="pos1YLabel"
         virtualName="" explicitFocusOrder="0" pos="8 56 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="pos1ZLabel" id="9deec04ec5fb5ccb" memberName="pos1ZLabel"
         virtualName="" explicitFocusOrder="0" pos="8 88 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="pos2XLabel" id="76ce5205bdfd67e8" memberName="pos2XLabel"
         virtualName="" explicitFocusOrder="0" pos="8 200 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="pos2YLabel" id="ee5c0539260c65bf" memberName="pos2YLabel"
         virtualName="" explicitFocusOrder="0" pos="8 232 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
  <LABEL name="pos2ZLabel" id="26413c707935ac1d" memberName="pos2ZLabel"
         virtualName="" explicitFocusOrder="0" pos="8 264 40 16" textCol="fff4efe7"
         edTextCol="ff000000" edBkgCol="0" labelText="Base" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Futura-Light"
         fontsize="14" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
