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
    gameTrakToggle->setRadioGroupId (1);
    gameTrakToggle->addListener (this);
    gameTrakToggle->setToggleState (true, dontSendNotification);
    gameTrakToggle->setColour (ToggleButton::textColourId, Colour (0xfff4efe7));

    addAndMakeVisible (leapToggle = new ToggleButton ("new toggle button"));
    leapToggle->setButtonText (TRANS("leapToggle"));
    leapToggle->setRadioGroupId (1);
    leapToggle->addListener (this);
    leapToggle->setColour (ToggleButton::textColourId, Colour (0xfff4efe7));

    addAndMakeVisible (customToggle = new ToggleButton ("Custom Toggle"));
    customToggle->setButtonText (TRANS("Custom"));
    customToggle->setRadioGroupId (1);
    customToggle->addListener (this);
    customToggle->setColour (ToggleButton::textColourId, Colour (0xfff4efe7));

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

    setSize (200, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

OscTab::~OscTab()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
	disconnect();
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

    g.fillAll (Colour (0xff303030));

    g.setColour (Colour (0xfff4efe7));
    g.setFont (Font ("Futura-Light", 15.00f, Font::plain));
    g.drawText (TRANS("UDP PORT"),
                35, 17, 76, 30,
                Justification::centredLeft, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void OscTab::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    connectButton->setBounds (51, 85, 99, 24);
    gameTrakToggle->setBounds (29, 134, 150, 24);
    leapToggle->setBounds (29, 158, 150, 24);
    customToggle->setBounds (29, 182, 150, 24);
    portBox->setBounds (26, 45, 150, 24);
    calButton->setBounds (24, 237, 153, 30);
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
                 snapPixels="8" snapActive="0" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="200" initialHeight="300">
  <METHODS>
    <METHOD name="visibilityChanged()"/>
  </METHODS>
  <BACKGROUND backgroundColour="ff303030">
    <TEXT pos="35 17 76 30" fill="solid: fff4efe7" hasStroke="0" text="UDP PORT"
          fontname="Futura-Light" fontsize="15" bold="0" italic="0" justification="33"/>
  </BACKGROUND>
  <TEXTBUTTON name="Connect Button" id="60989ea07129e409" memberName="connectButton"
              virtualName="" explicitFocusOrder="0" pos="51 85 99 24" buttonText="connect"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TOGGLEBUTTON name="Game Trak Toggle" id="bfe23abfc4f7aba8" memberName="gameTrakToggle"
                virtualName="" explicitFocusOrder="0" pos="29 134 150 24" txtcol="fff4efe7"
                buttonText="GameTrak" connectedEdges="0" needsCallback="1" radioGroupId="1"
                state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="9d12b9422a587b7b" memberName="leapToggle"
                virtualName="" explicitFocusOrder="0" pos="29 158 150 24" txtcol="fff4efe7"
                buttonText="leapToggle" connectedEdges="0" needsCallback="1"
                radioGroupId="1" state="0"/>
  <TOGGLEBUTTON name="Custom Toggle" id="27d5a5c7d880eafc" memberName="customToggle"
                virtualName="" explicitFocusOrder="0" pos="29 182 150 24" txtcol="fff4efe7"
                buttonText="Custom" connectedEdges="0" needsCallback="1" radioGroupId="1"
                state="0"/>
  <COMBOBOX name="PortBox" id="ff405dc967a0db0e" memberName="portBox" virtualName=""
            explicitFocusOrder="0" pos="26 45 150 24" editable="1" layout="33"
            items="6448&#10;7000" textWhenNonSelected="6448" textWhenNoItems="(no choices)"/>
  <TEXTBUTTON name="Calibration Button" id="cf9ed1489412dca2" memberName="calButton"
              virtualName="" explicitFocusOrder="0" pos="24 237 153 30" buttonText="Calibrate!"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
