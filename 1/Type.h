#pragma once
#include <iostream>
#include "Helper.h"

class Type
{
	bool _isTemp;
	std::string _varName;
public:
	Type(std::string varName, bool isTemp = false);
	
	virtual	bool isPrintable() const = 0;
	virtual std::string toString() const = 0;

	std::string getVarName() const { return _varName; };
	void setVarName(std::string newVarName) { _varName = newVarName; };

	virtual std::string getType() const = 0;

	bool getTemp() { return this->_isTemp; };
	void setTemp(bool newTemp) { _isTemp = newTemp; };
};
