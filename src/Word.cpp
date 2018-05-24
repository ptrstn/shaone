#include <bitset>
#include <sstream>
#include <iomanip>
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

Word Word::operator+=(const Word &other) {
    mValue += other.mValue;
    return *this;
}

Word Word::operator~() const {
    return Word(~mValue);
}

std::string Word::asHex() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(8) << std::hex << mValue;
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Word &word) {
    return os << word.value();
}

Word operator+(const Word &a, const Word &b) {
    return Word{a.value() + b.value()};
}

Word operator&(const Word &a, const Word &b) {
    return Word(a.value() & b.value());
}

Word operator|(const Word &a, const Word &b) {
    return Word(a.value() | b.value());
}

Word operator^(const Word &a, const Word &b) {
    return Word(a.value() ^ b.value());
}

bool operator==(const Word& lhs, const Word& rhs){
    return lhs.value() == rhs.value();
}

bool operator==(const Word& lhs, uint32_t rhs){
    return lhs.value() == rhs;
}