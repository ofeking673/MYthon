#pragma once
#include "Type.h"
#include <vector>


class Sequence : public Type {
public:
	Sequence(std::string varName, bool isTemp = false) : Type(varName, isTemp) {};
	virtual std::string getType() const = 0;
};