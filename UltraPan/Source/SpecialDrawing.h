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
	SpDraw() : radius(15), horScale(1), verScale(1){
		setMaxAndMinValues(10, -10, 10, -10, 10, -10);
	};
	
	
	void drawCoordSphere(Graphics& g, float x, float  y, float  z){
		
		float depthScale = (zMax-z)/(zMax-zMin) * 0.5 + 0.5;
		float heightScale = (yMax-y)/(yMax-yMin) * 0.8 + 0.2;
		chanHor = horScale * x * depthScale;
		chanVer = - verScale * y * depthScale;
		chanVerS= (zMax-z) * depthScale;
		radi = radius * (depthScale * 0.9 + 0.1);
		
		
		g.setColour ((Colours::black).withAlpha(0.5f));
		g.fillEllipse (baseHor - radi * heightScale +
					   5 * chanHor,
					   baseVer - radi * heightScale/4.f +
					   2 * chanVerS + 85,
					   radi * heightScale * 2,
					   radi * heightScale / 2);
		
		g.setGradientFill (ColourGradient (baseColor,
										   baseHor + 5.75 * (chanHor),
										   baseVer + 5 * (chanVer) - radi,
										   baseColor.darker(1.f),
										   baseHor + 4.25 * (chanHor),
										   baseVer + 5 * (chanVer) + radi,
										   true));
		
		g.fillEllipse (baseHor - radi + 5 * (chanHor),
					   baseVer - radi + 5 * (chanVer),
					   radi * 2,
					   radi * 2);
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
	
	void setScale (float newHorScale, float newVerScale) {
		horScale = newHorScale;
		verScale = newVerScale;
	}
	
private:
	float chanHor, chanVer,	chanVerS;
	float radius;
	float xMax, xMin, yMax, yMin, zMax, zMin;
	float radi, baseHor, baseVer;
	float horScale, verScale;
	Colour baseColor;
};


#endif  // SPECIALDRAWING_H_INCLUDED
