#ifndef CPP_KATAS_CAESAR_TWO_H
#define CPP_KATAS_CAESAR_TWO_H

#include <string>
#include <vector>

class CaesarTwo {
public:
    static std::vector<std::string> encodeStr(const std::string &cleartext, int shift);

    static std::string decode(std::vector<std::string> &chunks);
};

#endif //CPP_KATAS_CAESAR_TWO_H
