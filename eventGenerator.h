#pragma once

#include "usefulInfo.h"
#include "eventSources.h"
#include "genericEvent.h"


class eventGenerator
{
public:
	eventGenerator(usefulInfo* _I);
	~eventGenerator();
	void generateEvent();
	genericEvent* getNextEvent();

private:
	usefulInfo* I;
};

