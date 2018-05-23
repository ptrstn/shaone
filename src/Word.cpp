#include <bitset>
#include "Word.h"

Word::Word(unsigned int value): mValue(value) {}

std::string Word::asBinary() const {
    std::bitset<32> bitset(mValue);
    return bitset.to_string();
}

Word Word::rotateLeft(unsigned int amount) const {
    return Word{mValue << amount | mValue >>(32-amount)};
}

std::uint32_t Word::value() const {
    return mValue;
}

std::ostream &operator<<(std::ostream &os, const Word &word) {
    return os << word.value();
}

Word operator+(const Word &a, const Word &b) {
    return Word{a.value() + b.value()};
}
