#pragma once

typedef enum { NO_EV, PUT, GET, QUIT, HELP, CLEAR, DATA, ACK, WRQ, RRQ, ERROR, LAST_DATA, TIMEOUT } eventCode;

class genericEvent
{
public:
	genericEvent();
	~genericEvent();
	eventCode getEventCode() { return evCode; };

private:
	eventCode evCode;
};

