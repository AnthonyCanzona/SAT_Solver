#ifndef AND_NODE_H
#define AND_NODE_H

#include "Expr.h"
#include "NANDExpr.h"

class ANDExpr;

class ANDExpr : public Expr {
public:
    ANDExpr(const std::shared_ptr<Expr>& left, const std::shared_ptr<Expr>& right)
        : left(left), right(right) {}

    std::string getValue() const override { return Keywords::AND; }
    std::shared_ptr<Expr> getLeft() const override { return left; }
    std::shared_ptr<Expr> getRight() const override { return right; }
    std::shared_ptr<Expr> toNANDExpr() const override;

private:
    std::shared_ptr<Expr> left;
    std::shared_ptr<Expr> right;
};

#endif
