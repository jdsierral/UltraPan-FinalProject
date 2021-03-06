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

#ifndef __JUCE_HEADER_AB5D0B9CFEE158F0__
#define __JUCE_HEADER_AB5D0B9CFEE158F0__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Conversion.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class OscTab  : public Component,
                private OSCReceiver,
                private OSCReceiver::ListenerWithOSCAddress<OSCReceiver::MessageLoopCallback>,
                public ButtonListener,
                public ComboBoxListener
{
public:
    //==============================================================================
    OscTab (UltraPanAudioProcessor& p);
    ~OscTab();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	enum TypeCoord {
		cart,
		polar
	};

	void oscMessageReceived (const OSCMessage& message) override;
	void showConnectionErrorMessage (const String& messageText);

	void update();
	void updateNumChannels(int ins, int outs);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void visibilityChanged() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	UltraPanAudioProcessor& processor;
	bool status;
	int udpPort = 6448;
	TypeCoord typeCoord = polar;
	double azimuL = 1, elevaL = 1, depthL = 1;
	double azimuR = 1, elevaR = 1, depthR = 1;

	Vector3D<double> posL, posR, deltaL, deltaR;

    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TextButton> connectButton;
    ScopedPointer<ToggleButton> gameTrakToggle;
    ScopedPointer<ToggleButton> leapToggle;
    ScopedPointer<ToggleButton> customToggle;
    ScopedPointer<ComboBox> portBox;
    ScopedPointer<TextButton> calButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscTab)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_AB5D0B9CFEE158F0__
