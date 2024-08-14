#pragma once
#include "Type.h"

class boolean : public Type {
	bool _value;
public:
	boolean(std::string value,std::string varName="TempBool", bool temp = false) : Type(varName, temp), _value(Helper::getBooleanValue(value)) {};
	
	virtual	bool isPrintable() const { return true; };
	virtual std::string toString() const { return Helper::getBooleanVal(getValue()); };

	bool getValue() const { return _value; };
	void setValue(bool value) { _value = value; };

	virtual std::string getType() const { return "Bpol"; };

};