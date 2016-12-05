/*
  ==============================================================================

    Pink.h
    Created: 4 Dec 2016 8:51:21pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef PINK_H_INCLUDED
#define PINK_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class PinkNoise {
public:
	PinkNoise() : b0(0), b1(0), b2(0) {};
	float tick() {
		white = 2 * (rand.nextFloat()-0.5);
		b0 = 0.99765 * b0 + white * 0.0990460;
		b1 = 0.96300 * b1 + white * 0.2965164;
		b2 = 0.57000 * b2 + white * 1.0526913;
		return b0 + b1 + b2 + white * 0.1848;
	}
	
private:
	float white, b0, b1, b2;
	Random rand;
	
};



#endif  // PINK_H_INCLUDED
