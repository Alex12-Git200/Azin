#pragma once
#include "ast.hpp"
#include <string>

enum ValueType
{
    VAL_INT,
    VAL_STRING
};

struct Value
{
    ValueType type;
    int int_value;
    std::string string_value;
};

Value exec_expr(Expr* e);
void exec_stmt(Stmt* s);
