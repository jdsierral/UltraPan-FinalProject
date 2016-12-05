/*
  ==============================================================================

    SpecialDrawing.h
    Created: 30 Nov 2016 11:45:03pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef SPECIALDRAWING_H_INCLUDED
#define SPECIALDRAWING_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class SpDraw {
public:
	SpDraw(){};
	
	
	void drawCoordSphere(Graphics& g, float x, float  y, float  z){
		chanHor = x * (zMax-z)/(zMax-zMin);
		chanVer = - y * (xMax-z)/(xMax-xMin);
		chanVerS= (zMax-z) * (zMax-z)/(zMax-zMin);
		radi = radius * (((zMax-z)/(zMax-zMin)) * 0.9 + 0.1);
		
		
		g.setColour (baseColor.darker(1));
		g.fillEllipse (baseHor - radi + 5 * chanHor,
					   baseVer - radi + 2 * chanVerS + 85,
					   radi * 2,
					   radi / 2);
		
		g.setGradientFill (ColourGradient (baseColor,
										   baseHor + 5.75 * (chanHor),
										   baseVer + 5 * (chanVer) - radi,
										   Colours::black,
										   baseHor + 4.25 * (chanHor),
										   baseVer + 5 * (chanVer) + radi,
										   true));
		
		g.fillEllipse (baseHor - radi + 5 * (chanHor),
					   baseVer - radi + 5 * (chanVer),
					   radi * 2,
					   radi * 2);
	}
	
	void drawTest(Graphics& g) {
		g.setColour(Colours::black);
		g.fillEllipse(20, 20, 100, 100);
	}
	
	void setMaxAndMinValues(float newXMax,float  newXMin,float  newYMax, float newYMin, float newZMax, float newZMin) {
		xMax = newXMax;
		xMin = newXMin;
		yMax = newYMax;
		yMin = newYMin;
		zMax = newZMax;
		zMin = newZMin;
	}
	
	void setBases(float newBaseHor, float newBaseVer) {
		baseHor = newBaseHor;
		baseVer = newBaseVer;
	}
	
	void setRadius (float newRadius) {
		radius = newRadius;
	}
	
	void setColour (Colour newColour) {
		baseColor = newColour;
	}
	
private:
	float chanHor, chanVer,	chanVerS;
	float radius;
	float xMax, xMin, yMax, yMin, zMax, zMin;
	float radi, baseHor, baseVer;
	Colour baseColor;
	
//    g.setGradientFill (ColourGradient (Colour (0xff0049a5),
//                                       328.0f, 152.0f,
//                                       Colours::black,
//                                       288.0f, 216.0f,
//                                       true));
//    g.fillEllipse (263.0f, 123.0f, 100.0f, 100.0f);
	
//	Colour (0xffb9a384)
//	Colour (0xff574326)
//	Colour (0xb3000000)
};


#endif  // SPECIALDRAWING_H_INCLUDED
