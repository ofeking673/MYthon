#pragma once
#include "Sequence.h"

class String : public Sequence {
	std::string _value;
public:
	String(std::string value,std::string varName="TempStr", bool isTemp = false) : Sequence(varName, isTemp), _value(Helper::isString(value) ? value : "") {};
	
	virtual	bool isPrintable() const { return true; };
	virtual std::string toString() const { return getValue(); };

	std::string getValue() const { return _value; };
	void setValue(std::string value) { _value = value; };

	virtual std::string getType() const { return "String"; };

};
