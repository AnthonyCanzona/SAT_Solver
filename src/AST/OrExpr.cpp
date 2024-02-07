#include "../../include/AST/ORExpr.h"

std::shared_ptr<Expr> ORExpr::toNANDExpr() const {
    std::shared_ptr<Expr> left_child = std::make_shared<NANDExpr>(getLeft(), getLeft());
    std::shared_ptr<Expr> right_child = std::make_shared<NANDExpr>(getRight(), getRight());
    return std::make_shared<NANDExpr>(left_child->toNANDExpr(), right_child->toNANDExpr());
}
