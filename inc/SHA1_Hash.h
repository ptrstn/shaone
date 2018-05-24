#pragma once

#include <Word.h>

struct SHA1_Hash {
    Word A;
    Word B;
    Word C;
    Word D;
    Word E;
};

std::ostream& operator<<(std::ostream& os, const SHA1_Hash& hash);
bool operator==(const SHA1_Hash& lhs, const std::string& rhs);