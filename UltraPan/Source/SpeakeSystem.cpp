/*
  ==============================================================================

    SpeakeSystem.cpp
    Created: 15 Nov 2016 7:46:01pm
    Author:  Juan David Sierra

  ==============================================================================
*/

#include "SpeakeSystem.h"


SpeakerSystem::SpeakerSystem(int numSpeakers){
	speaker.resize(numSpeakers);
	gain.resize(numSpeakers);
}

SpeakerSystem::~SpeakerSystem(){
}

void SpeakerSystem::setSpeakerPos(int numSpeaker, Vector3D<float> speakerPos){
}

Vector3D<float> SpeakerSystem::getSpeakerPos(int numSpeaker){
	return speaker[numSpeaker];
}


float SpeakerSystem::getGain(int numSpeaker){
	gain[numSpeaker] = computeGain(pos, speaker[numSpeaker]);
	return gain[numSpeaker];
}


void SpeakerSystem::setSourcePos(Vector3D<float> newPos){
	pos = newPos;
	updateGains();
}

void SpeakerSystem::setSourcePosX(float newXPos){
	pos.x = newXPos;
	updateGains();
}

void SpeakerSystem::setSourcePosY(float newYPos){
	pos.y = newYPos;
	updateGains();
}

void SpeakerSystem::setSourcePosZ(float newZPos){
	pos.z = newZPos;
	updateGains();
}

void SpeakerSystem::updateGains(){
	for (int i = 0; i < numSpkrs; i++) {
		gain[i] = computeGain(pos, speaker[i]);
	}
}

float SpeakerSystem::computeGain(Vector3D<float> sourcePos, Vector3D<float> speakerPos) {
	return powf(base, -(sourcePos - speakerPos).length());
}
