#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>

class Tokenizer;

class Tokenizer {
public:
    Tokenizer(const std::string& expression) : expression(expression), currentPos(0) {}

    std::vector<std::string> tokenize();
    std::string peekToken();
    std::string consumeToken();
    bool hasMoreTokens();

private:
    std::string expression;
    size_t currentPos;

    std::string getNextToken();
};

#endif
