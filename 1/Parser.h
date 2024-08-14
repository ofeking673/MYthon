#pragma once
#include "InterpreterException.h"
#include "SyntaxException.h"
#include "Type.h"
#include "Helper.h"
#include "Boolean.h"
#include "Integer.h"
#include "String.h"
#include "Void.h"
#include "NameErrorException.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>


class Parser
{
public:
    static Type* parseString(std::string str);
    static Type* getType(const std::string& str);
    ~Parser();

private:
    static bool makeAssignment(std::string str);
    static Type* getVariableValue(std::string str);
    static bool isLegalVarName(std::string str);
    static bool DoesExist(std::string str);
};
