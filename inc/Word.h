#pragma once

#include <string>

class Word {
public:
    Word(unsigned int value);
    Word rotateLeft(unsigned int amount) const;
    std::string asBinary()const;
    std::uint32_t value()const;
private:
    std::uint32_t mValue;

};
std::ostream& operator<<(std::ostream& os, const Word& word);
Word operator+(const Word& a, const Word& b);