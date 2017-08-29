#include "doctest.h"
#include "hexconverter.hpp"

#include <string>
#include <iostream>

TEST_CASE("Hex tests"){

    HexConverter hc;
    hc.setUpperCase();
    REQUIRE(hc.decodeFromHex("8") == "8");
    REQUIRE(hc.decodeFromHex(8) == "8");

    REQUIRE(hc.encodeIntoHex(0) == "0");
    REQUIRE(hc.encodeIntoHex(9) == "9");
    REQUIRE(hc.encodeIntoHex(10) == "A");
    REQUIRE(hc.encodeIntoHex(16) == "10");
    REQUIRE(hc.encodeIntoHex(255) == "FF");

    hc.setLowerCase();
    REQUIRE(hc.encodeIntoHex(0) == "0");
    REQUIRE(hc.encodeIntoHex(9) == "9");
    REQUIRE(hc.encodeIntoHex(10) == "a");
    REQUIRE(hc.encodeIntoHex(16) == "10");
    REQUIRE(hc.encodeIntoHex(255) == "ff");

    REQUIRE(hc.encodeIntoHex("a") == "61");
    REQUIRE(hc.encodeIntoHex("A") == "41");
    REQUIRE(hc.encodeIntoHex("0") == "30");
    REQUIRE(hc.encodeIntoHex("!") == "21");
    REQUIRE(hc.encodeIntoHex(" ") == "20");


    REQUIRE(hc.encodeIntoHex("asdf") == "61736466");
    REQUIRE(hc.encodeIntoHex("") == "");
    REQUIRE(hc.decodeFromHex("F") == "15");



}



