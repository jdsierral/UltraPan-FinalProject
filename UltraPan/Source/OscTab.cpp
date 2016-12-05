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

    addAndMakeVisible (gameTrakToggle = new ToggleButton ("Game Trak Toggle"));
    gameTrakToggle->setButtonText (TRANS("GameTrak"));
    gameTrakToggle->addListener (this);

    addAndMakeVisible (leapToggle = new ToggleButton ("new toggle button"));
    leapToggle->setButtonText (TRANS("leapToggle"));
    leapToggle->addListener (this);

    addAndMakeVisible (customToggle = new ToggleButton ("Custom Toggle"));
    customToggle->setButtonText (TRANS("Custom"));
    customToggle->addListener (this);

    addAndMakeVisible (portBox = new ComboBox ("PortBox"));
    portBox->setEditableText (true);
    portBox->setJustificationType (Justification::centredLeft);
    portBox->setTextWhenNothingSelected (TRANS("6448"));
    portBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    portBox->addItem (TRANS("6448"), 1);
    portBox->addItem (TRANS("7000"), 2);
    portBox->addListener (this);

    addAndMakeVisible (calButton = new TextButton ("Calibration Button"));
    calButton->setButtonText (TRANS("Calibrate!"));
    calButton->addListener (this);


    //[UserPreSize]

	if ((status = connect(udpPort))) {
		connectButton->setButtonText("Disconnect");
	} else {
		showConnectionErrorMessage ("Error: could not connect to UDP port 6448.");
	}

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
    gameTrakToggle = nullptr;
    leapToggle = nullptr;
    customToggle = nullptr;
    portBox = nullptr;
    calButton = nullptr;


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
    gameTrakToggle->setBounds (200, 24, 150, 24);
    leapToggle->setBounds (200, 48, 150, 24);
    customToggle->setBounds (200, 72, 150, 24);
    portBox->setBounds (24, 24, 150, 24);
    calButton->setBounds (392, 48, 128, 24);
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
		if (!status) {
			if ((status = connect(6448))){
				connectButton->setButtonText("Disconnect");
			} else {
				showConnectionErrorMessage ("Error: could not connect to UDP port 6448.");
			}
		} else {
			status = !disconnect();
			connectButton->setButtonText("Connect");
		}
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
    else if (buttonThatWasClicked == calButton)
    {
        //[UserButtonCode_calButton] -- add your button handler code here..
		deltaL = posL;
		deltaR = posR;
		repaint();
        //[/UserButtonCode_calButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void OscTab::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == portBox)
    {
        //[UserComboBoxCode_portBox] -- add your combo box handling code here..
		udpPort = portBox->getText().getIntValue();
        //[/UserComboBoxCode_portBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void OscTab::visibilityChanged()
{
    //[UserCode_visibilityChanged] -- Add your code here...
    //[/UserCode_visibilityChanged]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void OscTab::update() {

}

void OscTab::oscMessageReceived (const OSCMessage& message) {
	if (message.size() == 7 && message[0].isFloat32()){
		if (message[6].getInt32()) {

			azimuL = message[0].getFloat32() * 45;
			elevaL = message[1].getFloat32() * 45;
			depthL = (message[2].getFloat32()) * 30;
			Conv::sph2car(azimuL, elevaL, depthL, false, posL.x, posL.y, posL.z);
			*processor.pos1X = jlimit<float>(-10.f, 10.f, posL.x - deltaL.x);
			*processor.pos1Y = -jlimit<float>(-10.f, 10.f, 2 * (posL.y - deltaL.y));
			*processor.pos1Z = jlimit<float>(-10.f, 10.f, posL.z - deltaL.z);


			azimuR = message[3].getFloat32() * 45;
			elevaR = message[4].getFloat32() * 45;
			depthR = (message[5].getFloat32()) * 30;
			Conv::sph2car(azimuR, elevaR, depthR, false, posR.x, posR.y, posR.z);
			*processor.pos2X = jlimit<float>(-10.f, 10.f, posR.x - deltaR.x);
			*processor.pos2Y = -jlimit<float>(-10.f, 10.f, 2 * (posR.y - deltaR.y));
			*processor.pos2Z = jlimit<float>(-10.f, 10.f, posR.z - deltaR.z);
		}
	}
}

void OscTab::showConnectionErrorMessage (const String& messageText) {
	AlertWindow::showMessageBoxAsync (AlertWindow::WarningIcon,
									  "Connection error",
									  messageText,
									  "OK");
}

void OscTab::updateNumChannels(int ins, int outs) {

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
  <METHODS>
    <METHOD name="visibilityChanged()"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="-9 -3 617 131" fill="linear: 304 120, 304 0, 0=ff71c100, 1=ff4b8100"
          hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="Connect Button" id="60989ea07129e409" memberName="connectButton"
              virtualName="" explicitFocusOrder="0" pos="24 72 150 24" buttonText="connect"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="Game Trak Toggle" id="bfe23abfc4f7aba8" memberName="gameTrakToggle"
                virtualName="" explicitFocusOrder="0" pos="200 24 150 24" buttonText="GameTrak"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="9d12b9422a587b7b" memberName="leapToggle"
                virtualName="" explicitFocusOrder="0" pos="200 48 150 24" buttonText="leapToggle"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="Custom Toggle" id="27d5a5c7d880eafc" memberName="customToggle"
                virtualName="" explicitFocusOrder="0" pos="200 72 150 24" buttonText="Custom"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <COMBOBOX name="PortBox" id="ff405dc967a0db0e" memberName="portBox" virtualName=""
            explicitFocusOrder="0" pos="24 24 150 24" editable="1" layout="33"
            items="6448&#10;7000" textWhenNonSelected="6448" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="Calibration Button" id="cf9ed1489412dca2" memberName="calButton"
              virtualName="" explicitFocusOrder="0" pos="392 48 128 24" buttonText="Calibrate!"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
