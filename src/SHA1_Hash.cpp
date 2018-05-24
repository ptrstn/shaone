//
// Created by Spectre on 24.05.2018.
//

#include "SHA1_Hash.h"

std::ostream &operator<<(std::ostream &os, const SHA1_Hash &hash) {
    return os << hash.A << hash.B << hash.C << hash.D << hash.E;
}
