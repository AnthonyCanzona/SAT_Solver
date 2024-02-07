#include "../../include/AST/NOTExpr.h"

std::shared_ptr<Expr> NOTExpr::toNANDExpr() const {
    return std::make_shared<NANDExpr>(getLeft()->toNANDExpr(), getLeft()->toNANDExpr());
}

std::string NOTExpr::toString() const{
    return getValue() + " " + getLeft()->toString();
}