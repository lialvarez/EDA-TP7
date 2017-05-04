#include "eventSources.h"

NetworkEventSource::NetworkEventSource(){};
NetworkEventSource::~NetworkEventSource() {};
bool NetworkEventSource::isThereEvent() { return false; } //MALE: esta es la funcion que lee lo que le envian por red
void NetworkEventSource::setServerIP(std::string _serverIP)
{
	serverIP = _serverIP
}

std::string NetworkEventSource::getServerIP()
{
	return serverIP;
}

UserEventSource::UserEventSource() {};
UserEventSource::~UserEventSource() {}
bool UserEventSource::isThereEvent() { return false; };	//LICHA: esta es la funcion que lee el teclado


TimeoutEventSource::TimeoutEventSource() {};
TimeoutEventSource::~TimeoutEventSource() {}
bool TimeoutEventSource::isThereEvent() 
{ 
//TODO: escribir esto como la gente
/*	if (timer == TO_TIME)
	{
		evento_del_eventsource = ev_timeout;
		return true
	}
	else
	{
		evento_del_event_source = no_ev;
		return false
*/	};	//si hay timer con pdcurses, usar ese

SoftwareEventSource::SoftwareEventSource() {};
SoftwareEventSource::~SoftwareEventSource() {}
bool SoftwareEventSource::isThereEvent() { return false; };