#include "Word.h"
#include "catch.hpp"
#include <iostream>

TEST_CASE("Word"){
    Word w1 = 0B01001111000000000000000000001010;
    Word w2 = 0B11100000000000000000000101001001;
    Word w3 = 4294967295;
    Word w4 = -1234;

    SECTION("Constructor"){
        REQUIRE(w1.value() == 1325400074);
        REQUIRE(w2.value() == 3758096713);
        REQUIRE(w3.value() == 4294967295);
        REQUIRE(w4.value() == 4294966062);
    }

    SECTION("asBinary"){
        REQUIRE(w1.asBinary() == "01001111000000000000000000001010");
        REQUIRE(w2.asBinary() == "11100000000000000000000101001001");
        REQUIRE(w3.asBinary() == "11111111111111111111111111111111");
        REQUIRE(w4.asBinary() == "11111111111111111111101100101110");
    }

    SECTION("operator+"){
        REQUIRE((w1 + w2).value() == 0x2F000153);
    }

    SECTION("rotateLeft"){
        REQUIRE(w1.rotateLeft(5).asBinary() == "11100000000000000000000101001001");
    }

    SECTION("Bitwise AND"){
        REQUIRE((w1 & w2).asBinary() == "01000000000000000000000000001000");
    }

    SECTION("Bitwise OR"){
        REQUIRE((w1 | w2).asBinary() == "11101111000000000000000101001011");
    }

    SECTION("Bitwise XOR"){
        REQUIRE((w1 ^ w2).asBinary() == "10101111000000000000000101000011");
    }


    SECTION("Bitwise NOT"){
        REQUIRE((~w1).asBinary() == "10110000111111111111111111110101");
    }
}
 