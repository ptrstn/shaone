#include <MessageBlock.h>
#include <MessageSchedule.h>
#include "catch.hpp"

TEST_CASE("MessageSchedule"){
    MessageBlock mb{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789012"};
    //abcd efgh ijkl mnop qrst uvwx yzAB CDEF GHIJ KLMN OPQR STUV WXYZ 1234 5678 9012
    MessageSchedule ms(mb);

    SECTION("operator[]"){
        SECTION("0..15"){
            REQUIRE(ms[0].asBinary() == "01100001011000100110001101100100" ); //abcd
            REQUIRE(ms[3].asHex() == "6d6e6f70" ); //mnop
            REQUIRE(ms[4].asHex() == "71727374" ); //qrst
            REQUIRE(ms[9].asHex() == "4b4c4d4e" ); //KLMN
            REQUIRE(ms[14].asHex() == "35363738" ); //5678
            REQUIRE(ms[15].asBinary() == "00111001001100000011000100110010" ); //9012
        }
        SECTION("16..79"){
            //abcd 01100001 01100010 01100011 01100100 xor
            //ijkl 01101001 01101010 01101011 01101100 =
            //     00001000 00001000 00001000 00001000

            //GHIJ 01000111 01001000 01001001 01001010 xor
            //1234 00110001 00110010 00110011 00110100 =
            //     01110110 01111010 01111010 01111110

            //     00001000 00001000 00001000 00001000 xor
            //     01110110 01111010 01111010 01111110 =
            //     01111110 01110010 01110010 01110110

            REQUIRE(ms[16].asBinary() == "11111100111001001110010011101100" );

            //19-16=3:mnop 01101101 01101110 01101111 01110000
            //19-14=5:uvwx 01110101 01110110 01110111 01111000
            //             00011000 00011000 00011000 00001000

            //19-8=11:STUV 01010011 01010100 01010101 01010110
            //19-3=16:     01111110 01110010 01110010 01110110
            //             00101101 00100110 00100111 00100000

            //             00011000 00011000 00011000 00001000
            //             00101101 00100110 00100111 00100000
            //             00110101 00111110 00111111 00101000
            REQUIRE(ms[19].asBinary() == "01101111010100010101001101100101" );
            //TODO more cases
            //REQUIRE(ms[53].asBinary() == "??" );
            //REQUIRE(ms[79].asBinary() == "??" );
        }
    }
}

