#include "doctest.h"
#include "b64converter.hpp"

TEST_CASE("Base64 tests"){
    Base64Converter bc;

    REQUIRE(bc.encodeIntoBase64("test") == "dGVzdA==");

    REQUIRE(bc.encodeIntoBase64("I'm killing your brain like a poisonous mushroom") == 
            "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t");
}
