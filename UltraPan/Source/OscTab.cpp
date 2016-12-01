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

#include "OscTab.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
OscTab::OscTab (UltraPanAudioProcessor& p)
    : processor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (connectButton = new TextButton ("Connect Button"));
    connectButton->setButtonText (TRANS("connect"));
    connectButton->addListener (this);

    addAndMakeVisible (portTextEditor = new TextEditor ("Port Text Editor"));
    portTextEditor->setMultiLine (false);
    portTextEditor->setReturnKeyStartsNewLine (false);
    portTextEditor->setReadOnly (false);
    portTextEditor->setScrollbarsShown (true);
    portTextEditor->setCaretVisible (true);
    portTextEditor->setPopupMenuEnabled (true);
    portTextEditor->setText (String());

    addAndMakeVisible (gameTrakToggle = new ToggleButton ("Game Trak Toggle"));
    gameTrakToggle->setButtonText (TRANS("GameTrak"));
    gameTrakToggle->addListener (this);

    addAndMakeVisible (leapToggle = new ToggleButton ("new toggle button"));
    leapToggle->setButtonText (TRANS("leapToggle"));
    leapToggle->addListener (this);

    addAndMakeVisible (customToggle = new ToggleButton ("Custom Toggle"));
    customToggle->setButtonText (TRANS("Custom"));
    customToggle->addListener (this);


    //[UserPreSize]
	
	if (!(status = connect(6448)))
		showConnectionErrorMessage ("Error: could not connect to UDP port 9001.");
	
	// tell the component to listen for OSC messages matching this address:
	addListener (this, "/wek/inputs");
	//[/UserPreSize]

    setSize (600, 120);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OscTab::~OscTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    connectButton = nullptr;
    portTextEditor = nullptr;
    gameTrakToggle = nullptr;
    leapToggle = nullptr;
    customToggle = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void OscTab::paint (Graphics& g)
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

void OscTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    connectButton->setBounds (24, 72, 150, 24);
    portTextEditor->setBounds (24, 24, 150, 24);
    gameTrakToggle->setBounds (200, 24, 150, 24);
    leapToggle->setBounds (200, 48, 150, 24);
    customToggle->setBounds (200, 72, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void OscTab::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == connectButton)
    {
        //[UserButtonCode_connectButton] -- add your button handler code here..
        //[/UserButtonCode_connectButton]
    }
    else if (buttonThatWasClicked == gameTrakToggle)
    {
        //[UserButtonCode_gameTrakToggle] -- add your button handler code here..
        //[/UserButtonCode_gameTrakToggle]
    }
    else if (buttonThatWasClicked == leapToggle)
    {
        //[UserButtonCode_leapToggle] -- add your button handler code here..
        //[/UserButtonCode_leapToggle]
    }
    else if (buttonThatWasClicked == customToggle)
    {
        //[UserButtonCode_customToggle] -- add your button handler code here..
        //[/UserButtonCode_customToggle]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void OscTab::oscMessageReceived (const OSCMessage& message) {
	if (message.size() == 7 && message[0].isFloat32()){
		if (message[6].getInt32()) {
			*processor.xPos = message[0].getFloat32() * 10;
			*processor.yPos = message[1].getFloat32() * 10;
			*processor.zPos = message[2].getFloat32() * 10;
		}
	}
}

void OscTab::showConnectionErrorMessage (const String& messageText) {
	AlertWindow::showMessageBoxAsync (AlertWindow::WarningIcon,
									  "Connection error",
									  messageText,
									  "OK");
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="OscTab" componentName=""
                 parentClasses="public Component, private OSCReceiver, private OSCReceiver::ListenerWithOSCAddress&lt;OSCReceiver::MessageLoopCallback&gt;"
                 constructorParams="UltraPanAudioProcessor&amp; p" variableInitialisers="processor(p)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="600" initialHeight="120">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="-9 -3 617 131" fill="linear: 304 120, 304 0, 0=ff71c100, 1=ff4b8100"
          hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="Connect Button" id="60989ea07129e409" memberName="connectButton"
              virtualName="" explicitFocusOrder="0" pos="24 72 150 24" buttonText="connect"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="Port Text Editor" id="fd7879f5c8195a6" memberName="portTextEditor"
              virtualName="" explicitFocusOrder="0" pos="24 24 150 24" initialText=""
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <TOGGLEBUTTON name="Game Trak Toggle" id="bfe23abfc4f7aba8" memberName="gameTrakToggle"
                virtualName="" explicitFocusOrder="0" pos="200 24 150 24" buttonText="GameTrak"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="9d12b9422a587b7b" memberName="leapToggle"
                virtualName="" explicitFocusOrder="0" pos="200 48 150 24" buttonText="leapToggle"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Custom Toggle" id="27d5a5c7d880eafc" memberName="customToggle"
                virtualName="" explicitFocusOrder="0" pos="200 72 150 24" buttonText="Custom"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
