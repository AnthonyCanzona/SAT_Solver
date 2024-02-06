#include "../include/Tokenizer.h"

std::vector<std::string> Tokenizer::tokenize() {
    std::vector<std::string> tokens;

    while (hasMoreTokens()) {
        tokens.push_back(getNextToken());
    }

    return tokens;
}

std::string Tokenizer::peekToken() {
    size_t originalPos = currentPos;
    std::string token = getNextToken();
    currentPos = originalPos; 
    return token;
}

std::string Tokenizer::consumeToken() {
    return getNextToken();
}

bool Tokenizer::hasMoreTokens() {
    return currentPos < expression.size();
}

std::string Tokenizer::getNextToken() {
    std::string token;

    // Skip whitespace
    while (hasMoreTokens() && std::isspace(expression[currentPos])) {
        currentPos++;
    }

    // Check for parentheses
    if (hasMoreTokens() && (expression[currentPos] == '(' || expression[currentPos] == ')')) {
        token.push_back(expression[currentPos++]);
        return token;
    }

    // Read characters until a space or parenthesis is encountered
    while (hasMoreTokens() && !std::isspace(expression[currentPos]) && expression[currentPos] != '(' && expression[currentPos] != ')') {
        token.push_back(expression[currentPos++]);
    }

    return token;
}
