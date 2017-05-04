#include "eventGenerator.h"


eventGenerator::eventGenerator(usefulInfo* _I)
{
	I = _I;
}
eventGenerator::~eventGenerator() {};

void eventGenerator::generateEvent()
{
	if (I->software->isThereEvent())
		I->eventBuffer/*->insert(I->software->getEvent())*/;	//TODO: todavia no esta implementado el buffer ni sus funciones
	if (I->network->isThereEvent())
		I->eventBuffer/*->insert(I->network->getEvent())*/;
	if (I->timeout->isThereEvent())
		I->eventBuffer/*->insert(I->timeout->getEvent())*/;
	if (I->user->isThereEvent())
		I->eventBuffer/*->insert(I->user->getEvent())*/;
}

genericEvent * eventGenerator::getNextEvent()
{
//	return I->eventBuffer->getNextElement();	//TODO: todavia no esta implementado el buffer ni sus funciones
	return nullptr;
}
