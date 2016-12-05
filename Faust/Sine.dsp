declare name 		"DSP";
declare author 		"JuanSaudio";

//----------------------------------------------//
// 				A Simple Sine					//
//----------------------------------------------//

import("stdfaust.lib");

freq = hslider("freq", 1000, 0, 20000, 1) : si.smoo;
gain = hslider("gain", 1, 0, 1, 0.01) : si.smoo;

process = hgroup("Sine", os.osc(freq) * gain);
