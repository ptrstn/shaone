#include "SHA1_Hash.h"

std::ostream &operator<<(std::ostream &os, const SHA1_Hash &hash) {
    return os << hash.A.asHex() << hash.B.asHex() << hash.C.asHex() << hash.D.asHex() << hash.E.asHex();
}

bool operator==(const SHA1_Hash &lhs, const std::string &rhs) {
    return (lhs.A.asHex() + lhs.B.asHex() + lhs.C.asHex() + lhs.D.asHex() + lhs.E.asHex()) == rhs;
}
