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
GeneratorAudioProcessorEditor::GeneratorAudioProcessorEditor (GeneratorAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (gainSlider = new Slider ("Gain Slider"));
    gainSlider->setRange (0, 10, 0);
    gainSlider->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    gainSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    gainSlider->addListener (this);

    addAndMakeVisible (typeBox = new ComboBox ("Type Box"));
    typeBox->setEditableText (false);
    typeBox->setJustificationType (Justification::centredLeft);
    typeBox->setTextWhenNothingSelected (TRANS("Sine"));
    typeBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    typeBox->addItem (TRANS("Sine,"), 1);
    typeBox->addItem (TRANS("White,"), 2);
    typeBox->addItem (TRANS("Pink"), 3);
    typeBox->addListener (this);

    addAndMakeVisible (freqSlider = new Slider ("Freq Slider"));
    freqSlider->setRange (0, 20, 0.01);
    freqSlider->setSliderStyle (Slider::LinearHorizontal);
    freqSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 45, 20);
    freqSlider->addListener (this);

    addAndMakeVisible (toggleButton = new ToggleButton ("new toggle button"));
    toggleButton->setButtonText (TRANS("bypass"));
    toggleButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (200, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GeneratorAudioProcessorEditor::~GeneratorAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    gainSlider = nullptr;
    typeBox = nullptr;
    freqSlider = nullptr;
    toggleButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GeneratorAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (Font (32.50f, Font::plain));
    g.drawText (TRANS("Generator"),
                0, 25, 200, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GeneratorAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    gainSlider->setBounds ((getWidth() / 2) - (144 / 2), 80, 144, 120);
    typeBox->setBounds ((getWidth() / 2) - (150 / 2), 240, 150, 24);
    freqSlider->setBounds ((getWidth() / 2) - (150 / 2), 208, 150, 24);
    toggleButton->setBounds (0, getHeight() - 24, 72, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GeneratorAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == gainSlider)
    {
        //[UserSliderCode_gainSlider] -- add your slider handling code here..
        //[/UserSliderCode_gainSlider]
    }
    else if (sliderThatWasMoved == freqSlider)
    {
        //[UserSliderCode_freqSlider] -- add your slider handling code here..
        //[/UserSliderCode_freqSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void GeneratorAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == typeBox)
    {
        //[UserComboBoxCode_typeBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_typeBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void GeneratorAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton)
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
        //[/UserButtonCode_toggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GeneratorAudioProcessorEditor::timerCallback() {

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GeneratorAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="GeneratorAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(&amp;p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="200" initialHeight="300">
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="0 25 200 30" fill="solid: ff000000" hasStroke="0" text="Generator"
          fontname="Default font" fontsize="32.5" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="Gain Slider" id="392e7dfe68ba61a4" memberName="gainSlider"
          virtualName="" explicitFocusOrder="0" pos="0Cc 80 144 120" min="0"
          max="10" int="0" style="RotaryHorizontalVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <COMBOBOX name="Type Box" id="25740b727aa74d1" memberName="typeBox" virtualName=""
            explicitFocusOrder="0" pos="0Cc 240 150 24" editable="0" layout="33"
            items="Sine,&#10;White,&#10;Pink" textWhenNonSelected="Sine"
            textWhenNoItems="(no choices)"/>
  <SLIDER name="Freq Slider" id="5cc8d2c65de66654" memberName="freqSlider"
          virtualName="" explicitFocusOrder="0" pos="0Cc 208 150 24" min="0"
          max="20" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="45"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
  <TOGGLEBUTTON name="new toggle button" id="52e92db5d5e85163" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="0 0Rr 72 24" buttonText="bypass"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
