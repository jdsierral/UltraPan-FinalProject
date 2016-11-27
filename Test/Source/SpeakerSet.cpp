/*
  ==============================================================================

    SpeakerSet.cpp
    Created: 24 Nov 2016 4:57:14am
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "SpeakerSet.h"


SpeakerSet::SpeakerSet() : total{
}

SpeakerSet::~SpeakerSet(){
}
//=================================================================

void SpeakerSet::initilize() {
	for (int sp = 0; sp < totalNumSpeakers; sp++) {
		speaker[sp]->buildUserInterface(speakerParams[sp]);
		speaker[sp]->init(SR);
	}
}

//=================================================================

void SpeakerSet::setNumSpeakers(int newNumSpeakers){
	if (newNumSpeakers == totalNumSpeakers) {
	} else if (newNumSpeakers > totalNumSpeakers) {
		while (newNumSpeakers > speakerPos.size()) {
			speakerPos.add(new Vector3D<float>);
			speaker.add(new Delay());
		}
		totalNumSpeakers = newNumSpeakers;
		updateAllGains();
	} else if (newNumSpeakers < totalNumSpeakers) {
		while (newNumSpeakers < speakerPos.size()) {
			speakerPos.removeLast();
			speaker.removeLast();
		}
		totalNumSpeakers = newNumSpeakers;
		updateAllGains();
	}
}

//=================================================================

void SpeakerSet::setSourcePosition(Vector3D<float> newSourcePos){
	sourcePos = newSourcePos;
	
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

void SpeakerSet::setSpeakerPos(int numSpeaker, Vector3D<float> newSpeakerPos){
	speakerPos.set(numSpeaker, &newSpeakerPos);
	updateSpeakerGain(numSpeaker);
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

Vector3D<float> SpeakerSet::getSpeakerPos(int numSpeaker){
	return *speakerPos[totalNumSpeakers];
}

float SpeakerSet::getSpeakerGain(int numSpeaker){
	return gain[numSpeaker];
}

float SpeakerSet::getBase() {
	return base;
}

float SpeakerSet::getScale() {
	return scale;
}

//=================================================================

void SpeakerSet::updateAllGains() {
	for (int sp = 0; sp < totalNumSpeakers; sp++) {
		updateSpeakerGain(sp);
	}
}

void SpeakerSet::updateSpeakerGain(int numSpeaker) {
	float exponent = (sourcePos - *speakerPos[numSpeaker]).lengthSquared();
	gain.set(numSpeaker, scale * powf(base, -(exponent)));
}


