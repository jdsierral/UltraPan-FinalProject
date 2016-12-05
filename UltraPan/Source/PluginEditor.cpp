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
    : AudioProcessorEditor(&p), processor(p), ins(processor.getTotalNumInputChannels()), outs(processor.getTotalNumOutputChannels())
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (tabs = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabs->setTabBarDepth (24);
    tabs->addTab (TRANS("Main"), Colour (0x89003271), new MainTab (processor), true);
    tabs->addTab (TRANS("Config"), Colour (0x89003271), new SetupTab (processor), true);
    tabs->addTab (TRANS("Osc"), Colour (0x89003271), new OscTab (processor), true);
    tabs->setCurrentTabIndex (0);

    addAndMakeVisible (bypassButton = new ToggleButton ("Bypass Button"));
    bypassButton->setButtonText (TRANS("bypass"));
    bypassButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

	sourcePos.resize(ins);
	speakerPos.resize(outs);

	setLookAndFeel(&myLookAndFeel);

	mainTab = static_cast<MainTab*>(tabs->getTabContentComponent(0));
	setupTab = (SetupTab*)tabs->getTabContentComponent(1);
	oscTab = (OscTab*)tabs->getTabContentComponent(2);

	sourceDraw.resize(ins);
	speakerDraw.resize(outs);

//	jassert(isPositiveAndNotGreaterThan(sourceDraw.size(), processor.getTotalNumInputChannels()));
//	jassert(isPositiveAndNotGreaterThan(speakerDraw.size(), processor.getTotalNumOutputChannels()));

	for (int in = 0; in < sourceDraw.size(); in++) {
		sourceDraw[in].setBases(300, 150);
		sourceDraw[in].setMaxAndMinValues(sliderRange,
										  -sliderRange,
										  sliderRange,
										  -sliderRange,
										  sliderRange,
										  -sliderRange);
		sourceDraw[in].setRadius(15);
		if (in == 0)
			sourceDraw[in].setColour(Colours::red);
		if (in == 1)
			sourceDraw[in].setColour(Colours::blue);
	}


	for (int out = 0; out < speakerDraw.size(); out++) {
		speakerDraw[out].setBases(300, 150);
		speakerDraw[out].setMaxAndMinValues(sliderRange,
										   -sliderRange,
										   sliderRange,
										   -sliderRange,
										   sliderRange,
										   -sliderRange);
		speakerDraw[out].setRadius(15);
		speakerDraw[out].setColour(Colour (0xff0049a5));
	}

	update();

	startTimer(50);
    //[/Constructor]
}

UltraPanAudioProcessorEditor::~UltraPanAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    tabs = nullptr;
    bypassButton = nullptr;


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

	for (int in = 0; in < sourceDraw.size(); in++){
		sourceDraw[in].drawCoordSphere(g,
									   sourcePos[in].x,
									   sourcePos[in].y,
									   sourcePos[in].z);
	}

	for (int out = 0; out < speakerDraw.size(); out++) {
		speakerDraw[out].drawCoordSphere(g,
										 speakerPos[out].x,
										 speakerPos[out].y,
										 speakerPos[out].z);
	}

    //[/UserPaint]
}

void UltraPanAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    tabs->setBounds (0, 256, 600, 144);
    bypassButton->setBounds (528, 0, 72, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void UltraPanAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == bypassButton)
    {
        //[UserButtonCode_bypassButton] -- add your button handler code here..
		*processor.bypass = bypassButton->getToggleState();
        //[/UserButtonCode_bypassButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void UltraPanAudioProcessorEditor::timerCallback() {
	if (processor.getGuiFlag()) {
		mainTab->update();
		setupTab->update();
		oscTab->update();
		update();
		repaint();
	}
}

void UltraPanAudioProcessorEditor::update() {
	bypassButton->setToggleState(*processor.bypass, dontSendNotification);
	for (int in = 0; in < ins; in++) {
		sourcePos[in] = processor.getSourcePos(in);
	}

	for (int out = 0; out < outs; out++) {
		speakerPos[out] = processor.getSpeakerPos(out);
	}

}

void UltraPanAudioProcessorEditor::updateNumChannels(int ins, int outs) {
	sourcePos.resize(ins);
	speakerPos.resize(outs);
	sourceDraw.resize(ins);
	speakerDraw.resize(outs);
	
	for (int in = 0; in < sourceDraw.size(); in++) {
		sourceDraw[in].setBases(300, 150);
		sourceDraw[in].setMaxAndMinValues(sliderRange,
										  -sliderRange,
										  sliderRange,
										  -sliderRange,
										  sliderRange,
										  -sliderRange);
		sourceDraw[in].setRadius(15);
		if (in == 0)
			sourceDraw[in].setColour(Colours::red);
		if (in == 1)
			sourceDraw[in].setColour(Colours::blue);
	}
	
	for (int out = 0; out < speakerDraw.size(); out++) {
		speakerDraw[out].setBases(300, 150);
		speakerDraw[out].setMaxAndMinValues(sliderRange,
											-sliderRange,
											sliderRange,
											-sliderRange,
											sliderRange,
											-sliderRange);
		speakerDraw[out].setRadius(15);
		speakerDraw[out].setColour(Colour (0xff0049a5));
	}
	mainTab->updateNumChannels(ins, outs);
	setupTab->updateNumChannels(ins, outs);
	oscTab->updateNumChannels(ins, outs);
	
	update();
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
                 constructorParams="UltraPanAudioProcessor&amp; p" variableInitialisers="AudioProcessorEditor(&amp;p), processor(p), ins(processor.getTotalNumInputChannels()), outs(processor.getTotalNumOutputChannels())"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="-1 -8 601 408" fill=" radial: 304 168, -80 40, 0=ff71c100, 1=ff008000"
          hasStroke="0"/>
    <TEXT pos="39 51 200 30" fill="solid: ff000000" hasStroke="0" text="JuanSaudio"
          fontname="Gill Sans" fontsize="43.899999999999998579" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <TABBEDCOMPONENT name="Tab Component" id="2ec337020e87f883" memberName="tabs"
                   virtualName="" explicitFocusOrder="0" pos="0 256 600 144" orientation="top"
                   tabBarDepth="24" initialTab="0">
    <TAB name="Main" colour="89003271" useJucerComp="0" contentClassName="MainTab"
         constructorParams="processor" jucerComponentFile=""/>
    <TAB name="Config" colour="89003271" useJucerComp="0" contentClassName="SetupTab"
         constructorParams="processor" jucerComponentFile=""/>
    <TAB name="Osc" colour="89003271" useJucerComp="0" contentClassName="OscTab"
         constructorParams="processor" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <TOGGLEBUTTON name="Bypass Button" id="8adcb962da3936e4" memberName="bypassButton"
                virtualName="" explicitFocusOrder="0" pos="528 0 72 24" buttonText="bypass"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
