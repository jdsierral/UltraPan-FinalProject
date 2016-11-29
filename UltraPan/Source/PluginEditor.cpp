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
    : AudioProcessorEditor(&p), processor(p)
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
    tabs->addTab (TRANS("Main"), Colours::lightgrey, new MainTab (processor), true);
    tabs->addTab (TRANS("Config"), Colours::lightgrey, new SetupTab (processor), true);
    tabs->setCurrentTabIndex (0);

    addAndMakeVisible (toggleButton = new ToggleButton ("new toggle button"));
    toggleButton->setButtonText (TRANS("bypass"));
    toggleButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
	setLookAndFeel(&myLookAndFeel);
	startTimer(50);
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
    toggleButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void UltraPanAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setGradientFill (ColourGradient (Colour (0xff71c100),
                                       304.0f, 168.0f,
                                       Colours::green,
                                       static_cast<float> (-80), 40.0f,
                                       true));
    g.fillRect (-1, -8, 601, 408);

    g.setColour (Colours::black);
    g.setFont (Font ("Gill Sans", 43.90f, Font::plain));
    g.drawText (TRANS("JuanSaudio"),
                39, 51, 200, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..

	//DrawSphere XD

	chanHor = y * (xPosSlider->getMaximum()-x)/(xPosSlider->getMaximum()-xPosSlider->getMinimum());
	chanVer = - z * (yPosSlider->getMaximum()-x)/(yPosSlider->getMaximum()-yPosSlider->getMinimum());
	chanVerS= (xPosSlider->getMaximum()-x) * (xPosSlider->getMaximum()-x)/(xPosSlider->getMaximum()-xPosSlider->getMinimum());
	radi = 15 * (((xPosSlider->getMaximum()-x)/(xPosSlider->getMaximum()-xPosSlider->getMinimum())) * 0.9 + 0.1);


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

void UltraPanAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    xPosSlider->setBounds (24, 120, 150, 32);
    yPosSlider->setBounds (24, 152, 150, 32);
    zPosSlider->setBounds (24, 184, 150, 32);
    tabs->setBounds (0, 256, 600, 144);
    toggleButton->setBounds (528, 0, 72, 24);
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
		y = xPosSlider->getValue();
		*processor.xPos = y;
        //[/UserSliderCode_xPosSlider]
    }
    else if (sliderThatWasMoved == yPosSlider)
    {
        //[UserSliderCode_yPosSlider] -- add your slider handling code here..
		z = yPosSlider->getValue();
		*processor.yPos = z;
        //[/UserSliderCode_yPosSlider]
    }
    else if (sliderThatWasMoved == zPosSlider)
    {
        //[UserSliderCode_zPosSlider] -- add your slider handling code here..
		x = zPosSlider->getValue();
		*processor.zPos = x;
        //[/UserSliderCode_zPosSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void UltraPanAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton)
    {
        //[UserButtonCode_toggleButton] -- add your button handler code here..
		*processor.bypass = toggleButton->getToggleState();
        //[/UserButtonCode_toggleButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void UltraPanAudioProcessorEditor::timerCallback() {
	if (processor.getGuiFlag()) {
		repaint();
	}

}


//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="UltraPanAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="UltraPanAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(&amp;p), processor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="-1 -8 601 408" fill=" radial: 304 168, -80 40, 0=ff71c100, 1=ff008000"
          hasStroke="0"/>
    <TEXT pos="39 51 200 30" fill="solid: ff000000" hasStroke="0" text="JuanSaudio"
          fontname="Gill Sans" fontsize="43.899999999999998579" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="X Pos Slider" id="4c5e01c12c9ae086" memberName="xPosSlider"
          virtualName="" explicitFocusOrder="0" pos="24 120 150 32" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Y Pos Slider" id="5082a310d30c270b" memberName="yPosSlider"
          virtualName="" explicitFocusOrder="0" pos="24 152 150 32" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="Z Pos Slider" id="b4b331794686aab3" memberName="zPosSlider"
          virtualName="" explicitFocusOrder="0" pos="24 184 150 32" min="-10"
          max="10" int="0" style="LinearHorizontal" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"
          needsCallback="1"/>
  <TABBEDCOMPONENT name="Tab Component" id="2ec337020e87f883" memberName="tabs"
                   virtualName="" explicitFocusOrder="0" pos="0 256 600 144" orientation="top"
                   tabBarDepth="24" initialTab="0">
    <TAB name="Main" colour="ffd3d3d3" useJucerComp="0" contentClassName="MainTab"
         constructorParams="processor" jucerComponentFile=""/>
    <TAB name="Config" colour="ffd3d3d3" useJucerComp="0" contentClassName="SetupTab"
         constructorParams="processor" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <TOGGLEBUTTON name="new toggle button" id="8adcb962da3936e4" memberName="toggleButton"
                virtualName="" explicitFocusOrder="0" pos="528 0 72 24" buttonText="bypass"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
