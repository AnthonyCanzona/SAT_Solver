#include "../include/BooleanParser.h"

std::shared_ptr<Expr> BooleanParser::parse() {
    return parseExpression();
}

std::shared_ptr<Expr> BooleanParser::parseExpression() {
    std::shared_ptr<Expr> left = parseTerm();

    while (tokenizer.peekToken() == Constants::OR) {
        tokenizer.consumeToken();
        std::shared_ptr<Expr> right = parseTerm();
        left = std::make_shared<ORExpr>(left, right);
    }

    return left;
}

std::shared_ptr<Expr> BooleanParser::parseTerm() {
    std::shared_ptr<Expr> left = parseFactor();

    while (tokenizer.peekToken() == Constants::AND) {
        tokenizer.consumeToken();
        std::shared_ptr<Expr> right = parseFactor();
        left = std::make_shared<ANDExpr>(left, right);
    }

    return left;
}

std::shared_ptr<Expr> BooleanParser::parseFactor() {
    if (tokenizer.peekToken() == Constants::NOT) {
        tokenizer.consumeToken();
        return std::make_shared<NOTExpr>(parseFactor());
    } 
    else {
        return parsePrimary();
    }
}

std::shared_ptr<Expr> BooleanParser::parsePrimary() {
    if (tokenizer.peekToken() == Constants::TRUE || tokenizer.peekToken() == Constants::FALSE) {
        bool value = (tokenizer.consumeToken() == Constants::TRUE);
        return std::make_shared<ConstExpr>(value);
    } 
    else if (tokenizer.peekToken().find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz_") == std::string::npos) {
        // Assuming a valid variable name is composed of letters and underscores
        return std::make_shared<VarExpr>(tokenizer.consumeToken());
    } 
    else if (tokenizer.peekToken() == "(") {
        tokenizer.consumeToken(); // Consume '('
        std::shared_ptr<Expr> expr = parseExpression();
        if (tokenizer.consumeToken() != ")") {
            throw std::runtime_error("Expected ')' after expression.");
        }
        return expr;
    } 
    else {
        throw std::runtime_error("Unexpected token: " + tokenizer.peekToken());
    }
}
