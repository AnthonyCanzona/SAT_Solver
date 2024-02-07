#include "../../include/AST/VarExpr.h"

std::shared_ptr<Expr> VarExpr::toNANDExpr() const {
    return std::make_shared<VarExpr>(name);
}

std::string VarExpr::toString() const {
    return getValue();
}