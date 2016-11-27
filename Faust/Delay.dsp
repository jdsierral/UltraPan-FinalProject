declare name 		"DSP";
declare author 		"JuanSaudio";

//----------------------------------------------//
// 				A Simple Delay					//
//----------------------------------------------//

import("stdfaust.lib");

delay = hslider("delay", 0, 0, 65536, 0.01) : si.smoo;
gain = hslider("gain", 1, 0, 1, 0.01) : si.smoo;

process = hgroup("Sp", _ : de.sdelay(65536, 512, delay) * gain );
