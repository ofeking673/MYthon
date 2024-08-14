#include "IndentationException.h"


IndentationException::IndentationException()
{
}

const char* IndentationException::what() const noexcept
{
	return "IndentationError: unexpected indent";
}