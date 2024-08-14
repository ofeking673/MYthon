#pragma once
#include "InterpreterException.h"


class IndentationException : public InterpreterException
{
public:
	IndentationException();
	virtual const char* what() const noexcept;
};
