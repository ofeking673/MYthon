#include "Type.h"
#include "InterpreterException.h"
#include "NameErrorException.h"
#include "Parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Ofek Dory"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;
	
	// get new command from user
	while (input_string != "quit()")
	{
		// parsing command
		try
		{
			Type* ok = Parser::parseString(input_string);
			if (ok)
			{
				std::cout << ok->toString() << std::endl;
				if (ok->getTemp())
				{
					delete ok;
				}

			}
		}
		catch (const NameErrorException& e)
		{
			std::cout << e.what() << std::endl; 
			input_string = "";
			continue;
		}


		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}

	return 0;
}
