#pragma once
#include "Type.h"


class integer : public Type
{
	int _value;
public:

	integer(std::string value, std::string varName="TempInt", bool isTemp = false) : Type(varName, isTemp)
	{
		Helper::removeLeadingZeros(value);
		_value = atoi(value.c_str());
	};

	virtual	bool isPrintable() const { return true; };
	virtual std::string toString() const { return std::to_string(getValue()); };

	int getValue() const { return _value; };
	void setValue(int value) { _value = value; };

	virtual std::string getType() const { return "Int"; };
};