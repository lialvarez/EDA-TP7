#pragma once

#include "eventSources.h"

class usefulInfo
{
public:
	usefulInfo();
	~usefulInfo();

	NetworkEventSource* network;	//TODO: ponerle getters quizas? quedaria mas prolijo o es al pedo??
	UserEventSource* user;
	TimeoutEventSource* timeout;
	SoftwareEventSource* software;

	genericEvent* eventBuffer;	//TODO: implementar un buffer posta
};

