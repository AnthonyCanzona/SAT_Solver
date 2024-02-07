#include "../../include/AST/NANDExpr.h"

std::shared_ptr<Expr> NANDExpr::toNANDExpr() const {
    return std::make_shared<NANDExpr>(getLeft()->toNANDExpr(), getRight()->toNANDExpr());
}