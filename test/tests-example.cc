#include "catch.hpp"

TEST_CASE("Example Unit-Test"){
    SECTION("Example Section 1"){
        REQUIRE(1 == 1);
    }

    SECTION("Example Section 2"){
        REQUIRE(1 != 0);
    }
}