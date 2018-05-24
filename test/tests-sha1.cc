#include <SHA1.h>
#include "Word.h"
#include "catch.hpp"

TEST_CASE("SHA-1"){

    SECTION("Short Message"){
        SHA1 s1{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ12"};
        REQUIRE(s1.hash() == "a294e923aeebc6e8142c0e1774cbeb84c028881b");
    }

    SECTION("2 Block Message"){
        SHA1 s1{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789012"};
        REQUIRE(s1.hash() == "bcab303508c3df0357cbe0c08cc1da3cfc0211ac");
    }

    SECTION("3 Block Message"){
        SHA1 s1{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ12abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ12abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ12"};
        REQUIRE(s1.hash() == "0162ccb529dd10f4ba0c7a82a87db32adc4feb41");
    }

    SECTION("Random Message"){
        SHA1 s1{"dkhfgfkdfghlydskdufhlsughewiuhgilu"};
        REQUIRE(s1.hash() == "f62220dd819173ac0eb7064466e565e60f8d09c1");
    }
}