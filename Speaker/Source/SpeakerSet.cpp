/*
  ==============================================================================

    SpeakerSet.cpp
    Created: 26 Nov 2016 12:38:32am
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "SpeakerSet.h"


SpeakerSet::SpeakerSet() : totalNumSpeakers(0){
}

SpeakerSet::~SpeakerSet(){
}
//=================================================================

void SpeakerSet::init() {
	for (int sp = 0; sp < totalNumSpeakers; sp++) {
		speakers[sp]->init(SR);
	}
}

//=================================================================

void SpeakerSet::setNumSpeakers(int newNumSpeakers){
	if (newNumSpeakers > totalNumSpeakers) {
		while (newNumSpeakers > totalNumSpeakers) {
			speakers.add(new Speaker());
			totalNumSpeakers = speakers.size();
		}
	} else if (newNumSpeakers < totalNumSpeakers) {
		while (newNumSpeakers < totalNumSpeakers) {
			speakers.removeLast();
			totalNumSpeakers = speakers.size();
		}
	}
}

void SpeakerSet::setBufferSize(int bufSize){
	for (int sp = 0; sp < totalNumSpeakers; sp++) {
		speakers[sp]->buffer.setSize(1, bufSize);
	}
}

//=================================================================

void SpeakerSet::setSourcePosition(Vector3D<float> newSourcePos){
	sourcePos = newSourcePos;
	updateAllGains();
}

void SpeakerSet::setSourceXPosition(float newSourceXPos){
	sourcePos.x = newSourceXPos;
	updateAllGains();
}

void SpeakerSet::setSourceYPosition(float newSourceYPos){
	sourcePos.y = newSourceYPos;
	updateAllGains();
}

void SpeakerSet::setSourceZPosition(float newSourceZPos){
	sourcePos.z = newSourceZPos;
	updateAllGains();
}

void SpeakerSet::setSpeakerPos(int sp, Vector3D<float> newSpeakerPos){
	speakers[sp]->pos = newSpeakerPos;
	updateSpeakerGain(sp);
}

void SpeakerSet::setBase(float newBase) {
	base = newBase;
	updateAllGains();
}

void SpeakerSet::setScale(float newScale) {
	scale = newScale;
	updateAllGains();
}

//=================================================================

Vector3D<float> SpeakerSet::getSourcePosition(){
	return sourcePos;
}

Vector3D<float> SpeakerSet::getSpeakerPos(int sp){	
	return speakers[sp]->pos;
}

float SpeakerSet::getSpeakerGain(int sp){
	return speakers[sp]->params.getParamValue("");
}

float SpeakerSet::getBase() {
	return base;
}

float SpeakerSet::getScale() {
	return scale;
}

//=================================================================

void SpeakerSet::compute(AudioSampleBuffer& inBuffer, AudioSampleBuffer& outBuffer) {
	int bufSize = outBuffer.getNumSamples();
	for (int sp = 0; sp < totalNumSpeakers; sp++) {
		speakers[sp]->buffer.copyFrom(0, 0, inBuffer, 0, 0, bufSize);
		speakers[sp]->compute();
		outBuffer.addFrom(sp, 0, speakers[sp]->buffer, 0, 0, bufSize);
	}
}

//=================================================================

void SpeakerSet::updateAllGains() {
	for (int sp = 0; sp < totalNumSpeakers; sp++) {
		updateSpeakerGain(sp);
	}
}

void SpeakerSet::updateSpeakerGain(int sp) {
	float exponent = (sourcePos - speakers[sp]->pos).lengthSquared();
	speakers[sp]->params.setParamValue("", scale * powf(base, -(exponent)));
}
