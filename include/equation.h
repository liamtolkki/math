#pragma once
#ifdef DEVELOPMENT_MODE
#include "allheaders.h"
#else
#include <mathlib/allheaders.h>
#endif
#include <vector>
#include <unordered_map>
/*
uses all headers so that it will have access
to every single function in the library for
parsing purposes
*/

enum class TokenType
{                // the 6 basic token types
    Number,      // 1.0, 3.4, ...
    Operator,    // +,-,*,/,^,...
    Variable,    // x, y, z, x_0, x_1, x_2, ....
    Parenthesis, // (,)
    Function,    // sin(x), cos(x), sqrt(x), ...
    Invalid      // any token that isn't recognized by the tokenizer
};

struct Token
{
    TokenType type;
    std::string value;
};

class Equation
{
public:
    std::string equation;
    int variables;                           // the number of variables in the equation
    decimalType evaluate(decimalType *list); // 'list' is the list of variables: {x, y, z, ....}
    std::vector<Token> tokenize();
};