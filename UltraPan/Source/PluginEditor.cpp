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
UltraPanAudioProcessorEditor::UltraPanAudioProcessorEditor (UltraPanAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (xPosSlider = new Slider ("X Pos Slider"));
    xPosSlider->setRange (-10, 10, 0);
    xPosSlider->setSliderStyle (Slider::LinearHorizontal);
    xPosSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    xPosSlider->addListener (this);

    addAndMakeVisible (yPosSlider = new Slider ("Y Pos Slider"));
    yPosSlider->setRange (-10, 10, 0);
    yPosSlider->setSliderStyle (Slider::LinearHorizontal);
    yPosSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    yPosSlider->addListener (this);

    addAndMakeVisible (zPosSlider = new Slider ("Z Pos Slider"));
    zPosSlider->setRange (-10, 10, 0);
    zPosSlider->setSliderStyle (Slider::LinearHorizontal);
    zPosSlider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    zPosSlider->addListener (this);

    addAndMakeVisible (tabs = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabs->setTabBarDepth (24);
    tabs->addTab (TRANS("Main"), Colours::lightgrey, new MainTab(), true);
    tabs->addTab (TRANS("Config"), Colours::lightgrey, new SetupTab(), true);
    tabs->setCurrentTabIndex (0);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

UltraPanAudioProcessorEditor::~UltraPanAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    xPosSlider = nullptr;
    yPosSlider = nullptr;
    zPosSlider = nullptr;
    tabs = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void UltraPanAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.setFont (Font ("Gill Sans", 43.90f, Font::plain));
    g.drawText (TRANS("JuanSaudio"),
                39, 51, 200, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void UltraPanAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    xPosSlider->setBounds (24, 112, 150, 32);
    yPosSlider->setBounds (24, 144, 150, 32);
    zPosSlider->setBounds (24, 176, 150, 32);
    tabs->setBounds (0, 280, 600, 120);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void UltraPanAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == xPosSlider)
    {
        //[UserSliderCode_xPosSlider] -- add your slider handling code here..
		*processor.xPos = xPosSlider->getValue();
        //[/UserSliderCode_xPosSlider]
    }
    else if (sliderThatWasMoved == yPosSlider)
    {
        //[UserSliderCode_yPosSlider] -- add your slider handling code here..
		*processor.yPos = yPosSlider->getValue();
        //[/UserSliderCode_yPosSlider]
    }
    else if (sliderThatWasMoved == zPosSlider)
    {
        //[UserSliderCode_zPosSlider] -- add your slider handling code here..
		*processor.zPos = zPosSlider->getValue();
        //[/UserSliderCode_zPosSlider]
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

<JUCER_COMPONENT documentType="Component" className="UltraPanAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor"
                 constructorParams="UltraPanAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="39 51 200 30" fill="solid: ff000000" hasStroke="0" text="JuanSaudio"
          fontname="Gill Sans" fontsize="43.899999999999998579" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="X Pos Slider" id="4c5e01c12c9ae086" memberName="xPosSlider"
          virtualName="" explicitFocusOrder="0" pos="24 112 150 32" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Y Pos Slider" id="5082a310d30c270b" memberName="yPosSlider"
          virtualName="" explicitFocusOrder="0" pos="24 144 150 32" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Z Pos Slider" id="b4b331794686aab3" memberName="zPosSlider"
          virtualName="" explicitFocusOrder="0" pos="24 176 150 32" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <TABBEDCOMPONENT name="Tab Component" id="2ec337020e87f883" memberName="tabs"
                   virtualName="" explicitFocusOrder="0" pos="0 280 600 120" orientation="top"
                   tabBarDepth="24" initialTab="0">
    <TAB name="Main" colour="ffd3d3d3" useJucerComp="0" contentClassName="MainTab"
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Config" colour="ffd3d3d3" useJucerComp="0" contentClassName="SetupTab"
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
