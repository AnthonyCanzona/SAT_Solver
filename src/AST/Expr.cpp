#include "../../include/AST/Expr.h"

std::string Expr::toString() const{
    return "( " + getLeft()->toString() + " " + getValue() + " " + getRight()->toString() + " )";
}