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

#include "Info.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Info::Info ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (webLink = new HyperlinkButton (TRANS("JuanSaudio"),
                                                      URL ("www.JuanSaudio.com")));
    webLink->setTooltip (TRANS("www.JuanSaudio.com"));
    webLink->setButtonText (TRANS("JuanSaudio"));
    webLink->setColour (HyperlinkButton::textColourId, Colour (0x54f4efe7));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 200);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Info::~Info()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    webLink = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Info::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0x9c000000));

    g.setColour (Colour (0xfff4efe7));
    g.drawRoundedRectangle (9.0f, 8.0f, 283.0f, 183.0f, 10.000f, 0.900f);

    g.setColour (Colour (0xfff4efe7));
    g.setFont (Font ("Futura-Light", 25.90f, Font::plain));
    g.drawText (TRANS("UltraPan"),
                58, 50, 200, 30,
                Justification::centred, true);

    g.setColour (Colour (0xfff4efe7));
    g.setFont (Font ("Futura-Light", 15.00f, Font::plain));
    g.drawText (TRANS("Created By: JuanSaudio"),
                52, 97, 200, 30,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Info::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    webLink->setBounds (76, 129, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Info::mouseDown (const MouseEvent& event) {
	this->setVisible(false);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Info" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="0"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="300"
                 initialHeight="200">
  <BACKGROUND backgroundColour="9c000000">
    <ROUNDRECT pos="9 8 283 183" cornerSize="10" fill="solid: 61a52a" hasStroke="1"
               stroke="0.9, mitered, butt" strokeColour="solid: fff4efe7"/>
    <TEXT pos="58 50 200 30" fill="solid: fff4efe7" hasStroke="0" text="UltraPan"
          fontname="Futura-Light" fontsize="25.899999999999998579" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="52 97 200 30" fill="solid: fff4efe7" hasStroke="0" text="Created By: JuanSaudio"
          fontname="Futura-Light" fontsize="15" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <HYPERLINKBUTTON name="webLink" id="d081d7fb4920502b" memberName="webLink" virtualName=""
                   explicitFocusOrder="0" pos="76 129 150 24" tooltip="www.JuanSaudio.com"
                   textCol="54f4efe7" buttonText="JuanSaudio" connectedEdges="0"
                   needsCallback="0" radioGroupId="0" url="www.JuanSaudio.com"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
