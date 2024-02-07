#include <iostream>
#include "../include/BooleanParser.h"

int main() {

    std::string booleanExpression = "(A AND B) OR (NOT C)";
    BooleanParser booleanParser = BooleanParser(booleanExpression);

    try {
        std::shared_ptr<Expr> parsedExpression = booleanParser.parse();
        std::shared_ptr<Expr> nandExpression = parsedExpression->toNANDExpr();

        std::cout << "Original Expression: " << booleanExpression << std::endl;
        std::cout << "Parsed Form: " << nandExpression->toString() << std::endl;
        std::cout << "NAND Form: " << nandExpression->toString() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; 
    }

    return 0; 
}
