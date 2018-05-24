#include <Stage.h>
#include <iostream>
#include "catch.hpp"

TEST_CASE("Stage"){
    SECTION("constants"){
        Word c1 = Stage<1>::constant;
        Word c2 = Stage<2>::constant;
        Word c3 = Stage<3>::constant;
        Word c4 = Stage<4>::constant;
        REQUIRE(c1 == 0x5A827999 );
        REQUIRE(c2 == 0x6ED9EBA1 );
        REQUIRE(c3 == 0x8F1BBCDC );
        REQUIRE(c4 == 0xCA62C1D6 );
    }

    Word c = 0B11100000000000000000000101001001;
    Word b = 0B01001111000100000000000000001010;
    Word d = 0B11100111000110000100010010011001;

    SECTION("Stage 1"){
        Word f = Stage<1>::f(b, c, d);
        REQUIRE(f.asBinary() == "11100000000010000100010010011001");
        REQUIRE(f == 3758638233);
    }

    SECTION("Stage 2"){
        Word f = Stage<2>::f(b, c, d);
        REQUIRE(f == 1208501722);
    }

    SECTION("Stage 3"){
        Word f = Stage<3>::f(b, c, d);
        REQUIRE(f == 3876585481);
    }
    SECTION("Stage 4"){
        Word f = Stage<4>::f(b, c, d);
        REQUIRE(f == 1208501722);
    }
}

