#include "../include/BooleanParser.h"

int main() {

    BooleanParser booleanParser;
    std::string booleanExpression = "(A AND B) OR (NOT C)";

    try {
        auto parsedExpression = booleanParser.parse(booleanExpression);
        auto nandExpression = parsedExpression->toNANDExpr();

        std::cout << "Original Expression: " << booleanExpression << std::endl;
        std::cout << "Parsed Form: " << nandExpression->toString() << std::endl;
        std::cout << "NAND Form: " << nandExpression->toString() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1; 
    }

    return 0; 
}
