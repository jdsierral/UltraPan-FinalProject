declare name 		"DSP";
declare author 		"JuanSaudio";

//----------------------------------------------//
// 				A Simple Delay					//
//----------------------------------------------//

import("stdfaust.lib");

del = hslider("delay", 0.01, 0.01, 65536, 0.01) : si.smoo;
gain = hslider("gain", 1, 0, 1, 0.01) : si.smoo;

process = hgroup("Sp", _ : de.fdelay(65536, del) * gain );
