#pragma once
#include "../1/InterpreterException.h"
#include <iostream>
#include <string>
#include <sstream>

class NameErrorException : public InterpreterException
{
	std::string name;
public:
	NameErrorException(std::string var) : InterpreterException() {
		name = "NameError: name '" + var + "' is not defined.";
	};
	virtual const char* what() const noexcept {
		return name.c_str();
	};
};


