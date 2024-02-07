#ifndef KEYWORDS_H
#define KEYWORDS_H

#include <string>

class Keywords {
public:
    inline static const std::string AND = "AND";
    inline static const std::string OR = "OR";
    inline static const std::string NOT = "NOT";
    inline static const std::string NAND = "NAND";
    inline static const std::string TRUE = "1";
    inline static const std::string FALSE = "0";

    Keywords() = delete;
};

#endif // KEYWORDS_H
