#pragma once

#include <string>
#include "genericEventSource.h"

class NetworkEventSource : public genericEventSource
{
public:
	NetworkEventSource();
	~NetworkEventSource();
	bool isThereEvent();
	void setServerIP(std::string _serverIP);
	std::string getServerIP();
private:
	std::string serverIP;
};
class UserEventSource : public genericEventSource
{
public:
	UserEventSource();
	~UserEventSource();
	bool isThereEvent();
};
class TimeoutEventSource : public genericEventSource
{
public:
	TimeoutEventSource();
	~TimeoutEventSource();
	bool isThereEvent();
	//startTimer()	//TODO: agregar el timer de timeout y sus funciones de control
	//stopTimer()
	//getTimer()
};
class SoftwareEventSource : public genericEventSource
{
public:
	SoftwareEventSource();
	~SoftwareEventSource();
	bool isThereEvent();
	//loadSoftwareEvent(ev); //TODO: agregar una funcion para cargar eventos de software
};