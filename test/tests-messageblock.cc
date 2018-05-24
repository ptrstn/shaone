#include <MessageBlock.h>
#include "catch.hpp"

TEST_CASE("MessageBlock"){
    MessageBlock mb{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789012"};
    REQUIRE(mb.str().length()==64);
    REQUIRE(mb.str()=="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789012");
}

