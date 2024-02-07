#include "../../include/AST/ConstExpr.h"

std::shared_ptr<Expr> ConstExpr::toNANDExpr() const {
    return std::make_shared<ConstExpr>(value);
}

std::string ConstExpr::toString() const {
    return getValue();
}