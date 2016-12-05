/*
  ==============================================================================

    SpeakerSet.cpp
    Created: 26 Nov 2016 3:15:12pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "SpeakerSet.h"

SpeakerSet::SpeakerSet() : totalNumSpeakers(0), base(1.02), scale(1) {
}

SpeakerSet::~SpeakerSet(){
}
//=================================================================

void SpeakerSet::init(int sampleRate) {
	SR = sampleRate;
	for (int sp = 0; sp < totalNumSpeakers; sp++) {
		speakers[sp]->init(SR);
		speakers[sp]->name = String("speaker" + String(sp));
	}
}

//=================================================================

void SpeakerSet::setNumSpeakers(int newNumSpeakers){
	if (newNumSpeakers != totalNumSpeakers) {
		while (newNumSpeakers > totalNumSpeakers) {
			speakers.add(new Speaker());
			totalNumSpeakers = speakers.size();
		}
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
	updateAllSpeakers();
}

void SpeakerSet::setSourcePosX(float newPosX){
	sourcePos.x = newPosX;
	updateAllSpeakers();
}

void SpeakerSet::setSourcePosY(float newPosY){
	sourcePos.y = newPosY;
	updateAllSpeakers();
}

void SpeakerSet::setSourcePosZ(float newPosZ){
	sourcePos.z = newPosZ;
	updateAllSpeakers();
}

void SpeakerSet::setSpeakerPos(int sp, Vector3D<float> newPos){
	speakers[sp]->pos = newPos;
	checkMinDistance();
	updateSpeaker(sp);
}

void SpeakerSet::setSpeakerPosX(int sp, float newPosX){
	speakers[sp]->pos.x = newPosX;
	checkMinDistance();
	updateSpeaker(sp);
}

void SpeakerSet::setSpeakerPosY(int sp, float newPosY){
	speakers[sp]->pos.y = newPosY;
	checkMinDistance();
	updateSpeaker(sp);
}

void SpeakerSet::setSpeakerPosZ(int sp, float newPosZ){
	speakers[sp]->pos.z = newPosZ;
	checkMinDistance();
	updateSpeaker(sp);
}

void SpeakerSet::setBase(float newBase) {
	base = newBase;
	updateAllSpeakers();
}

void SpeakerSet::setScale(float newScale) {
	scale = newScale;
	updateAllSpeakers();
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

String SpeakerSet::getSpeakerName(int sp){
	return speakers[sp]->name;
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

void SpeakerSet::updateAllSpeakers() {
	for (int sp = 0; sp < totalNumSpeakers; sp++) {
		updateSpeaker(sp);
	}
}

void SpeakerSet::updateSpeaker(int sp) {
	float exponent = (sourcePos - speakers[sp]->pos).lengthSquared();
	speakers[sp]->params.setParamValue("/Sp/gain", powf(base, -(exponent)));
	
	float dist = std::sqrt(exponent) + speakers[sp]->pos.length() - minDist;
	speakers[sp]->params.setParamValue("/Sp/delay", dist * SR/c);
}

void SpeakerSet::checkMinDistance(){
	jassert(totalNumSpeakers > 0);
	minDist = speakers[0]->pos.length();
	for (int sp = 0; sp < totalNumSpeakers; sp++) {
		float speakerDist = speakers[sp]->pos.length();
		if (speakerDist < minDist)
			minDist = speakerDist;
	}
}

void SpeakerSet::printParam(int sp) {
	DBG(speakers[sp]->name << " : " <<
		String(speakers[sp]->pos.x) << ", " <<
		String(speakers[sp]->pos.y) << ", " <<
		String(speakers[sp]->pos.z));
}
