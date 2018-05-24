#pragma once

#include <string>

class Word {
public:
    Word(unsigned int value = 0);
    Word rotateLeft(unsigned int amount) const;
    std::string asBinary()const;
    std::string asHex()const;
    std::uint32_t value()const;

    Word operator+=(const Word& other);
    Word operator~() const;
private:
    std::uint32_t mValue = 0;
};

std::ostream& operator<<(std::ostream& os, const Word& word);
Word operator+(const Word& a, const Word& b);
Word operator&(const Word& a, const Word& b);
Word operator|(const Word& a, const Word& b);
Word operator^(const Word& a, const Word& b);
bool operator==(const Word& lhs, const Word& rhs);
bool operator==(const Word& lhs, uint32_t rhs);