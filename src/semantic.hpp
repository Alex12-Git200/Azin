#pragma once

#include "ast.hpp"
#include <unordered_map>
#include <vector>
#include <string>

namespace azin {

enum class SymbolKind {
    Variable,
    Function
};

struct Symbol {
    SymbolKind kind;
    Type type; // return type for function, type for variable
    std::vector<Type> paramTypes; // only used if function
    bool isArray = false;
    int arraySize = -1;
};


class SymbolTable {
public:
    void enterScope();
    void exitScope();

    bool declare(const std::string& name, const Symbol& symbol);
    Symbol* lookup(const std::string& name);

private:
    std::vector<std::unordered_map<std::string, Symbol>> scopes;
    
};

class SemanticAnalyzer {
public:
    void analyze(Program& program);

private:
    SymbolTable symbols;
    Type currentFunctionReturnType;
    bool foundReturnInCurrentFunction = false;

    void analyzeFunction(FunctionDecl& fn);
    void analyzeBlock(BlockStmt* block);
    void analyzeStatement(Stmt* stmt);
    Type analyzeExpression(Expr* expr);
    bool areTypesCompatible(const Type& from, const Type& to);
};

}
