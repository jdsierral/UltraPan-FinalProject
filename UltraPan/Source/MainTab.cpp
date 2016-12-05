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
    baseSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
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

    addAndMakeVisible (toggleButton = new ToggleButton ("new toggle button"));
    toggleButton->setButtonText (String());
    toggleButton->addListener (this);

    addAndMakeVisible (inputSelectBox = new ComboBox ("Input Select Box"));
    inputSelectBox->setEditableText (false);
    inputSelectBox->setJustificationType (Justification::centredLeft);
    inputSelectBox->setTextWhenNothingSelected (String());
    inputSelectBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    inputSelectBox->addListener (this);


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
    pos1XSlider = nullptr;
    pos1YSlider = nullptr;
    pos1ZSlider = nullptr;
    pos2XSlider = nullptr;
    pos2YSlider = nullptr;
    pos2ZSlider = nullptr;
    toggleButton = nullptr;
    inputSelectBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainTab::paint (Graphics& g)
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
    //[/UserPaint]
}

void MainTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    mainVolSlider->setBounds (512, 24, 72, 80);
    baseSlider->setBounds (424, 72, 40, 40);
    pos1XSlider->setBounds (32, 24, 150, 16);
    pos1YSlider->setBounds (32, 56, 150, 16);
    pos1ZSlider->setBounds (32, 88, 150, 16);
    pos2XSlider->setBounds (224, 24, 150, 16);
    pos2YSlider->setBounds (224, 56, 150, 16);
    pos2ZSlider->setBounds (224, 88, 150, 16);
    toggleButton->setBounds (192, 64, 24, 21);
    inputSelectBox->setBounds (400, 24, 96, 24);
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
		
        //[/UserSliderCode_baseSlider]
    }
    else if (sliderThatWasMoved == pos1XSlider)
    {
        //[UserSliderCode_pos1XSlider] -- add your slider handling code here..
		*processor.pos1X = sliderThatWasMoved->getValue();
        //[/UserSliderCode_pos1XSlider]
    }
    else if (sliderThatWasMoved == pos1YSlider)
    {
        //[UserSliderCode_pos1YSlider] -- add your slider handling code here..
		*processor.pos1Y = sliderThatWasMoved->getValue();
        //[/UserSliderCode_pos1YSlider]
    }
    else if (sliderThatWasMoved == pos1ZSlider)
    {
        //[UserSliderCode_pos1ZSlider] -- add your slider handling code here..
		*processor.pos1Z = sliderThatWasMoved->getValue();
        //[/UserSliderCode_pos1ZSlider]
    }
    else if (sliderThatWasMoved == pos2XSlider)
    {
        //[UserSliderCode_pos2XSlider] -- add your slider handling code here..
		*processor.pos2X = sliderThatWasMoved->getValue();
        //[/UserSliderCode_pos2XSlider]
    }
    else if (sliderThatWasMoved == pos2YSlider)
    {
        //[UserSliderCode_pos2YSlider] -- add your slider handling code here..
		*processor.pos2Y = sliderThatWasMoved->getValue();
        //[/UserSliderCode_pos2YSlider]
    }
    else if (sliderThatWasMoved == pos2ZSlider)
    {
        //[UserSliderCode_pos2ZSlider] -- add your slider handling code here..
		*processor.pos2Z = sliderThatWasMoved->getValue();
        //[/UserSliderCode_pos2ZSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MainTab::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton)
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
		DBG("Havent done anything here!!!");
        //[/UserButtonCode_toggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void MainTab::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == inputSelectBox)
    {
        //[UserComboBoxCode_inputSelectBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_inputSelectBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
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
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="-9 -3 617 131" fill="linear: 304 120, 304 0, 0=ff71c100, 1=ff4b8100"
          hasStroke="0"/>
  </BACKGROUND>
  <SLIDER name="Main Volume Slider" id="48e517a99b24c0fe" memberName="mainVolSlider"
          virtualName="" explicitFocusOrder="0" pos="512 24 72 80" min="-60"
          max="12" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Base Slider" id="271c0bce09620c47" memberName="baseSlider"
          virtualName="" explicitFocusOrder="0" pos="424 72 40 40" min="1"
          max="1000" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos1XSlider" id="11759a50dc05a4c4" memberName="pos1XSlider"
          virtualName="" explicitFocusOrder="0" pos="32 24 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos1YSlider" id="3c232841636fc9d1" memberName="pos1YSlider"
          virtualName="" explicitFocusOrder="0" pos="32 56 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos1ZSlider" id="8cc1089f0229ede7" memberName="pos1ZSlider"
          virtualName="" explicitFocusOrder="0" pos="32 88 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos2XSlider" id="b46e098975ec1c6a" memberName="pos2XSlider"
          virtualName="" explicitFocusOrder="0" pos="224 24 150 16" min="-10"
          max="10" int="-10" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos2YSlider" id="7cd99f02df05bb9c" memberName="pos2YSlider"
          virtualName="" explicitFocusOrder="0" pos="224 56 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="pos2ZSlider" id="40bcc69e2e0325a6" memberName="pos2ZSlider"
          virtualName="" explicitFocusOrder="0" pos="224 88 150 16" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <TOGGLEBUTTON name="new toggle button" id="d4a62aae1fdb9f61" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="192 64 24 21" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <COMBOBOX name="Input Select Box" id="31a6d5668817e037" memberName="inputSelectBox"
            virtualName="" explicitFocusOrder="0" pos="400 24 96 24" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
