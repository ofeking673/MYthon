#pragma once
#include <exception>


class InterpreterException : public std::exception
{
public:
	InterpreterException() {};

	virtual const char* what() const noexcept {
		return "Interpreter exception\n";
	};
};
