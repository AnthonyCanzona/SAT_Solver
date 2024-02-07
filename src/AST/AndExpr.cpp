#include "../../include/AST/ANDExpr.h"

std::shared_ptr<Expr> ANDExpr::toNANDExpr() const {
    std::shared_ptr<Expr> child = std::make_shared<NANDExpr>(getLeft(), getRight());
    return std::make_shared<NANDExpr>(child->toNANDExpr(), child->toNANDExpr());
}
