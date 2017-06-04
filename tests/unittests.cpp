#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "hexconverter.hpp"
#include "b64converter.hpp"
#include <string>
#include <iostream>
TEST_CASE("Hex tests", "[hex]"){
    HexConverter hc;


    REQUIRE(hc.encodeIntoUpperCase("asdf") == "61736466");
    REQUIRE(hc.encodeIntoLowerCase("asdf") == "61736466");
    REQUIRE(hc.encodeIntoUpperCase("") == "");
    REQUIRE(hc.decodeFromHex("FFFF") == "65535");
    REQUIRE(hc.decodeFromHex("FFF") == "4095");
    REQUIRE(hc.decodeFromHex("FF") == "255");
    REQUIRE(hc.decodeFromHex("F") == "15");
    REQUIRE(hc.decodeFromHex("8") == "8");
}


TEST_CASE("B64 tests", "[b64]"){
    Base64Converter bc;

}
