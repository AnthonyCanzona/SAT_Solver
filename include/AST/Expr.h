#ifndef EXPR_H
#define EXPR_H

#include <memory>
#include <string>
#include "Keywords.h"

class Expr;

class Expr {
public:
    virtual ~Expr() = default;
    virtual std::string getValue() const = 0;
    virtual std::shared_ptr<Expr> getLeft() const = 0;
    virtual std::shared_ptr<Expr> getRight() const = 0;
    virtual std::shared_ptr<Expr> toNANDExpr() const = 0;
    virtual std::string toString() const;

private:
    std::shared_ptr<Expr> left;
    std::shared_ptr<Expr> right;
};

#endif // EXPR_H
