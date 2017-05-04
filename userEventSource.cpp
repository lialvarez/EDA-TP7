#include "userEventSource.h"
#include "parseCmdLine.h"
#include "Callback.h"
#include <boost\algorithm\string\classification.hpp>
#include <boost\algorithm\string\split.hpp>


userEventSource::userEventSource()
{
	terminalWindow = initscr();
	clear();
	move(0, 0);
	printw("Client>");
	refresh();
}

userEventSource::~userEventSource()
{
}

void userEventSource::restartTerminal()
{
	clear();
	move(0, 0);
	printw("Client>");
	refresh();
}

bool userEventSource::isThereEvent()
{
	bool ret;
	inputChar = getch();
	
	switch (inputChar)
	{
	case ERR:

		ret = false;	//Si no se ingresa tecla, indica que no hay evento
		break;			//y no carga caracter en buffer.

	case BACKSPACE:

		//Si se apreta "backspace" borra y quita caracteres del buffer
		//hasta que llega el comienzo de la linea de comando
		//Tambien elimina los caracteres ingresados de la teminal
		if (buffer.size() > 0)
		{
			buffer.pop_back();
			delch();
		}
		if (terminalWindow->_curx == 10)	//Posicion donde arranca la linea de comando
		{
			terminalWindow->_curx++;	//Para que el cursor no pse vaya del area permitida
		}
		ret = false;	//No hay evento
		break;

	case ENTER:

		command = std::string(buffer.begin(), buffer.end());	//Almaceno la linea de comando ingresada en command
		std::transform(command.begin(), command.end(), command.begin(), tolower);	//
		boost::split(words, command, boost::is_any_of(", "), boost::token_compress_on);	//Se separan las palabras ingresadas
		
		if (words.size() == 1)
		{
			if (strcmp(words[0].c_str(), "help") == 0)
			{
				inputEvent = HELP;
				ret = true;
			}
			if (strcmp(words[0].c_str(), "quit") == 0)
			{
				inputEvent = QUIT;
				ret = true;
			}
		}
		else if(words.size() == 2)
		{
			if (strcmp(words[0].c_str(), "put") == 0)
			{
				fileToTransfer.open(words[1].c_str());
				if (fileToTransfer.fail())
				{
					ret = true;
					inputEvent = FILE_ERROR;
				}
				else
				{
					inputEvent = PUT;
					ret = true;
				}

			}

			if (strcmp(words[0].c_str(), "get") == 0)
			{
				fileToTransfer.open(words[1].c_str());
				if (fileToTransfer.fail())
				{
					ret = true;
					inputEvent = FILE_ERROR;
				}
				else
				{
					inputEvent = GET;
					ret = true;
				}

			}

			else
			{

			}
		}
		else
		{
			ret = true;
			inputEvent = INVALID;
		}
		break;

	default:
		//Si el caracter ingresado es un caracter valido(ningun caracter de control)
		//lo añade al buffer
		if (inputChar > ASCII_START && inputChar < ASCII_END)
		{
			buffer.push_back(inputChar);
			ret = false;
		}
		break;
	}
	return ret;
}
