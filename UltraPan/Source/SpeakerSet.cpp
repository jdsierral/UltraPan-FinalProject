/*
  ==============================================================================

    SpeakerSet.cpp
    Created: 26 Nov 2016 3:15:12pm
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
		speakers[sp]->name = String("Speaker: " + String(sp));
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

void SpeakerSet::setSourcePos(Vector3D<float> newPos){
	sourcePos = newPos;
	updateAllGains();
}

void SpeakerSet::setSourcePosX(float newPosX){
	sourcePos.x = newPosX;
	updateAllGains();
}

void SpeakerSet::setSourcePosY(float newPosY){
	sourcePos.y = newPosY;
	updateAllGains();
}

void SpeakerSet::setSourcePosZ(float newPosZ){
	sourcePos.z = newPosZ;
	updateAllGains();
}

void SpeakerSet::setSpeakerPos(int sp, Vector3D<float> newPos){
	speakers[sp]->pos = newPos;
	updateSpeakerGain(sp);
}

void SpeakerSet::setSpeakerPosX(int sp, float newPosX){
	speakers[sp]->pos.x = newPosX;
	updateSpeakerGain(sp);
}

void SpeakerSet::setSpeakerPosY(int sp, float newPosY){
	speakers[sp]->pos.x = newPosY;
	updateSpeakerGain(sp);
}

void SpeakerSet::setSpeakerPosZ(int sp, float newPosZ){
	speakers[sp]->pos.x = newPosZ;
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
	return speakers[sp]->params.getParamValue("/Sp/gain");
}

float SpeakerSet::getSpeakerDelay(int sp){
	return speakers[sp]->params.getParamValue("/Sp/gain");
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
	speakers[sp]->params.setParamValue("/Sp/gain", scale * powf(base, -(exponent)));
}
