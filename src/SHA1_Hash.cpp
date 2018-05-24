#include "SHA1_Hash.h"

std::ostream &operator<<(std::ostream &os, const SHA1_Hash &hash) {
    return os << hash.A.asHex() << hash.B.asHex() << hash.C.asHex() << hash.D.asHex() << hash.E.asHex();
}
