#pragma once
#include "genericEvent.h"

class genericEventSource
{
public:
	genericEventSource();
	~genericEventSource();

	virtual bool isThereEvent() = 0;	//forzar a hacer una funcion distinta de busqueda de eventos para cada fuente
	genericEvent* getEvent() { return event; };

protected:
	genericEvent* event;
};

