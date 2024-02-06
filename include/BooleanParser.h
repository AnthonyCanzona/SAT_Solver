#ifndef BOOLEAN_PARSER_H
#define BOOLEAN_PARSER_H

#include "AST/Expr.h"
#include "AST/ANDExpr.h"
#include "AST/ORExpr.h"
#include "AST/NOTExpr.h"
#include "AST/NANDExpr.h"
#include "AST/VarExpr.h"
#include "AST/ConstExpr.h"

#include "Tokenizer.h"
#include <stdexcept>

class BooleanParser;

class BooleanParser {
public:
    BooleanParser(const std::string& expression) : tokenizer(expression) {}

    std::shared_ptr<Expr> parse();

private:
    Tokenizer tokenizer;

    std::shared_ptr<Expr> parseExpression();
    std::shared_ptr<Expr> parseTerm();
    std::shared_ptr<Expr> parseFactor();
    std::shared_ptr<Expr> parsePrimary();
};

#endif
