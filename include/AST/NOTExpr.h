#ifndef NOT_NODE_H
#define NOT_NODE_H

#include "Expr.h"
#include "NANDExpr.h"

class NOTExpr;

class NOTExpr : public Expr {
public:
    NOTExpr(const std::shared_ptr<Expr>& operand) : operand(operand) {}

    std::string getValue() const override { return Constants::NOT; }
    std::shared_ptr<Expr> getLeft() const override { return operand; }
    std::shared_ptr<Expr> getRight() const override { return nullptr; }
    std::shared_ptr<Expr> toNANDExpr() const override;
    std::string toString() const override;

private:
    std::shared_ptr<Expr> operand;
};

#endif 
