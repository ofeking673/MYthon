#pragma once
#include "InterpreterException.h"


class SyntaxException : public InterpreterException {
public:
	SyntaxException() : InterpreterException() {};

	virtual const char* what() const noexcept { return "SyntaxError: Invalid syntax"; };
};