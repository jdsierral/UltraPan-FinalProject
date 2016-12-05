/*
  ==============================================================================

    ConversionHandling.h
    Created: 30 Nov 2016 9:27:37pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#ifndef CONVERSIONHANDLING_H_INCLUDED
#define CONVERSIONHANDLING_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "math.h"

class Conv {
public:
static void car2sph (double x, double y, double z, bool outRad,
                         int &azimu, int &eleva, double &depth) {
        depth = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        
        if (y != 0) {
            azimu = atan(x/y) + M_PI * sgnOf(x) * (1 - sgnOf(y))/(2);
        }
        
        if (x != 0 || y != 0 || z != 0) {
            eleva = atan(z/sqrt(pow(x,2) + pow(y,2)));
        }
        
        if (!outRad) {
            azimu = radiansToDegrees((double)azimu);
            eleva = radiansToDegrees((double)eleva);
        }
    }
    
    static void car2sph (double x, double y, double z, bool outRad,
                         double &azimu, double &eleva, double &depth) {
        depth = sqrt(pow(x,2) + pow(y,2) + pow(z,2));
        
        if (y != 0) {
            azimu = atan(x/y) + M_PI * sgnOf(x) * (1 - sgnOf(y))/(2);
        }
        
        if (x != 0 || y != 0 || z != 0) {
            eleva = atan(z/sqrt(pow(x,2) + pow(y,2)));
        }
        
        if (!outRad) {
            azimu = radiansToDegrees(azimu);
            eleva = radiansToDegrees(eleva);
        }
    }
    
    
    static void sph2car (double azimu, double eleva, double depth,
                         bool isRad, double &x, double &y, double &z) {
        if (!isRad) {
            azimu = degreesToRadians(azimu);
            eleva = degreesToRadians(eleva);
        }
        
		x = depth * cos(eleva) * sin(azimu);
        y = depth * cos(eleva) * cos(azimu);
        z = depth * sin(eleva);
    }
    
    static double sgnOf (double a) {
        return (a == 0 ? 1 : a/fabs(a));
    }
private:
	Conv(){}
};



#endif  // CONVERSIONHANDLING_H_INCLUDED
