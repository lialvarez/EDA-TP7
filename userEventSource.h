#ifndef USEREVENTSOURCE_H
#define USEREVENTSOURCE

#include "Screen.h"
#include "generEventSource.h"
#include <vector>
#include <fstream>

typedef enum { PUT, GET, QUIT, HELP, NO_EV, INVALID, FILE_ERROR, CLEAR_SCREEN }userEvents;

class userEventSource : public generEventSource
{
public:

	userEventSource();
	~userEventSource();
	bool isThereEvent();

	//Hay que crear las clases genericEvent primero
	//esta funcion deberia devolver el evnto ingresado
	//genericEvent *getEvent();

private:

	void restartTerminal();

	std::fstream fileToTransfer;
	
	std::vector<std::string> words;	//Vector para separar los argumentos ingresados
	std::vector<char> buffer;
	std::string command;
	
	int inputChar;
	char ** args;

	userEvents inputEvent;
};

#endif // !USEREVENTSOURCE_H