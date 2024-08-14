#include "Parser.h"
#include "IndentationException.h"
#include <iostream>

static std::unordered_map<std::string, Type*> _variables;


Type* Parser::parseString(std::string str)
{
	Type* ok = nullptr;
	std::string first, second;
	if (str.length() > 0)
	{
		if (str.c_str()[0] == ' ' || str.c_str()[0] == '\t')
		{
			throw IndentationException();
		}

		if (str.find('=') > 0 && str.find('=') < str.length() - 1)
		{
			if (str[str.find('=')] == ' ')
			{
				first = str.substr(0, str.find('=') - 1);
			}
			else
			{
				first = str.substr(0, str.find('='));
			}
			second = str.substr(str.find('=') + 1);
			Helper::trim(second);

			makeAssignment(str);

			ok = getType(second);

			if (ok == nullptr)
			{
				throw SyntaxException();
			}
			return ok;
		}

		if (DoesExist(str))
		{
			ok = getVariableValue(str);
			if (ok)
			{
				return ok;
			}
		}

		ok = getType(str);

		if (ok == nullptr)
		{
			delete ok;
			throw SyntaxException();
		}
	}



	return ok;
}

Type* Parser::getType(const std::string& str)
{
	std::string newStr;
	if (DoesExist(str))
	{
		newStr = _variables[str]->toString();
		
		if (Helper::isBoolean(newStr))
		{
			return new boolean(str, "", true);
		}
		else if (Helper::isInteger(newStr))
		{
			return new integer(str, "", true);
		}
		else if (Helper::isString(newStr))
		{
			return new String(str, "", true);
		}
		return nullptr;
	}

	if (Helper::isBoolean(str))
	{
		return new boolean(str,"", true);
	}
	else if(Helper::isInteger(str))
	{
		return new integer(str,"", true);
	}
	else if (Helper::isString(str))
	{
		return new String(str,"", true);
	}
	return nullptr;
}

Parser::~Parser()
{
	for (auto& ok : _variables)
	{
		delete ok.second;
	}
}

bool Parser::makeAssignment(std::string str)
{
	std::string first;

	if ( str[str.find('=')] == ' ')
	{
		first = str.substr(0, str.find('=') - 1);
	}
	else
	{
		first = str.substr(0, str.find('='));
	}
	Helper::trim(first);
	std::string second = str.substr(str.find('=') + 1);
	Helper::trim(second);
	
	if (!isLegalVarName(first))
	{
		throw NameErrorException(first);
	}
	if (DoesExist(second))
	{
		if (_variables[first])
		{
			delete _variables[first];
		}
		Type* secondItem = _variables[second];
		_variables[first] = getType(secondItem->toString());
		_variables[first]->setTemp(false);
		_variables[first]->setVarName(first);
		return true;
	}


	if (_variables[first])
	{
		delete _variables[first];
	}
	_variables[first] = getType(second);
	_variables[first]->setTemp(false);
	_variables[first]->setVarName(first);

	return true;
}

Type* Parser::getVariableValue(std::string str)
{
	auto it = _variables.find(str);
	if (it == _variables.end())
	{
		throw NameErrorException(str);
	}

	return it->second;
}

bool Parser::isLegalVarName(std::string str)
{
	if (isdigit(str.c_str()[0]))
	{
		return false;
	}
	for (auto it = str.begin(); it != str.end(); it++)
	{
		if (isalnum(*it) || *it == '_')
		{
			continue;
		}
		return false;
	}
	return true;
}

bool Parser::DoesExist(std::string str)
{
	return (_variables.find(str) != _variables.end());
}


