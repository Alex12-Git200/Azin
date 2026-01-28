// TODO: Make this acctually make assembly code

#include "codegen.hpp"
#include <iostream>
#include <stdexcept>
#include <unordered_map>

static std::unordered_map<std::string, int> variables;

Value exec_expr(Expr* e)
{
    // integer literal 
    if (e->type == EXPR_INT)
    {
        return { VAL_INT, e->int_value, "" };
    }

    // string literal 
    if (e->type == EXPR_STRING)
    {
        return { VAL_STRING, 0, e->string_value };
    }

    // variable reference 
    if (e->type == EXPR_VAR)
    {
        if (!variables.count(e->var_name))
            throw std::runtime_error("undefined variable: " + e->var_name);

        return { VAL_INT, variables[e->var_name], "" };
    }

    // function call 
    if (e->type == EXPR_CALL)
    {
        // builtin: io.out(...)
        if (e->module_name == "io" && e->func_name == "out")
        {
            Value arg = exec_expr(e->arg);

            if (arg.type == VAL_INT)
                std::cout << arg.int_value;
            else if (arg.type == VAL_STRING)
                std::cout << arg.string_value;
            else
                throw std::runtime_error("unsupported value type");

            return arg;
        }

        throw std::runtime_error("unknown function call: " +
                                 e->func_name + "@" + e->module_name);
    }

    throw std::runtime_error("invalid expression");
}

void exec_stmt(Stmt* s)
{
    if (s->type == STMT_DECL)
    {
        Value v = exec_expr(s->value);

        if (v.type != VAL_INT)
            throw std::runtime_error("int variables must be int");

        variables[s->var_name] = v.int_value;
        return;
    }
    // assignment 
    if (s->type == STMT_ASSIGN)
    {
        Value v = exec_expr(s->value);

        if (v.type != VAL_INT)
            throw std::runtime_error("only int variables supported");

        variables[s->var_name] = v.int_value;
        return;
    }

    // expression statement 
    if (s->type == STMT_EXPR)
    {
        exec_expr(s->value);
        return;
    }

    // return statement 
    if (s->type == STMT_RETURN)
    {
        exec_expr(s->value);
        return;
    }
}
