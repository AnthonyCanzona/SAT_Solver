#ifndef CONST_EXPR_H
#define CONST_EXPR_H

#include "Expr.h"

class ConstExpr;

class ConstExpr : public Expr {
public:
    ConstExpr(bool value) : value(value) {}

    std::string getValue() const override { return value ? Keywords::TRUE : Keywords::FALSE; }
    std::shared_ptr<Expr> getLeft() const override { return nullptr; }
    std::shared_ptr<Expr> getRight() const override { return nullptr; }
    std::shared_ptr<Expr> toNANDExpr() const override;
    std::string toString() const override;

private:
    bool value;
};

#endif