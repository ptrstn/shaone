#pragma once

#include "Word.h"

template<int N>
class Stage{
public:
    Word f(Word b, Word c, Word d);
    static const uint32_t constant;
};

template<>
class Stage<1> {
public:
    static Word f(Word b, Word c, Word d){
        return (b & c)| (b & d);
    }

    static const uint32_t constant = 0x5A827999;
};

template<>
class Stage<2> {
public:
    static Word f(Word b, Word c, Word d){
        return b ^ c ^ d;
    }

    static const uint32_t constant = 0x6ED9EBA1;
};

template<>
class Stage<3> {
public:
    static Word f(Word b, Word c, Word d){
        return (b & c) | (b & d) | (c & d);
    }

    static const uint32_t constant = 0x8F1BBCDC;
};



template<>
class Stage<4> {
public:
    static Word f(Word b, Word c, Word d){
        return b ^ c ^ d;
    }

    static const uint32_t constant = 0xCA62C1D6;
};