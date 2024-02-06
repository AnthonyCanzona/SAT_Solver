#include "../../include/AST/Expr.h"

std::string Expr::toString() const{
    return "( " + left->toString() + " " + getValue() + " " + right->toString() + " )";
}