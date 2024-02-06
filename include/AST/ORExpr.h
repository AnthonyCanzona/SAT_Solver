#ifndef OR_NODE_H
#define OR_NODE_H

#include "Expr.h"
#include "NANDExpr.h"

class ORExpr;

class ORExpr : public Expr {
public:
    ORExpr(const std::shared_ptr<Expr>& left, const std::shared_ptr<Expr>& right)
        : left(left), right(right) {}

    std::string getValue() const override { return Constants::OR; }
    std::shared_ptr<Expr> getLeft() const override { return left; }
    std::shared_ptr<Expr> getRight() const override { return right; }
    std::shared_ptr<Expr> toNANDExpr() const override;

private:
    std::shared_ptr<Expr> left;
    std::shared_ptr<Expr> right;
};

#endif // OR_NODE_H
