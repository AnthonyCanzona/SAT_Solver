#ifndef VAR_EXPR_H
#define VAR_EXPR_H

#include "Expr.h"

class VarExpr;

class VarExpr : public Expr {
public:
    VarExpr(std::string name) : name(name) {}

    std::string getValue() const override { return name; }
    std::shared_ptr<Expr> getLeft() const override { return nullptr; }
    std::shared_ptr<Expr> getRight() const override { return nullptr; }
    std::shared_ptr<Expr> toNANDExpr() const override;
    std::string toString() const override;

private:
    std::string name;
};

#endif