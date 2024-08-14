#pragma once
#include "Type.h"

class Void : public Type {
public:
	Void() : Type("", true) {};
	virtual	bool isPrintable() const { return false; };
	virtual std::string toString() const { return ""; };

	virtual std::string getType() const { return "Void"; };

};