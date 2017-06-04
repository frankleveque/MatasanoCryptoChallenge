/*
B64Converter - Tool for converting into and from base 64
===========================================================================
Copyright © 2014 Frank Leveque

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
===========================================================================
*/

#include "b64converter.hpp"
#include <bitset>
#include <vector>
#include "utility.hpp"

Base64Converter::Base64Converter()
{
    returnString.str("");
}

Base64Converter::~Base64Converter()
{

}

//! returns base64 encoded string
std::string Base64Converter::encodeIntoBase64(const std::string &input)
{
    returnString.str("");
    std::vector<bool> bits;

    //for every character, convert to bitset, then append bytes to vector
    for(unsigned int i=0; i < input.size(); ++i) {
        std::bitset<8> oct(input[i]);// 76543210 is order of bits
        for(int i=7; i>-1 ; --i) {
            bits.push_back(oct[i]);
        }
    }
    //bits should now contain bitstream to parse

    //convert 6bit groups to base64
    for(unsigned int i=0; i < bits.size(); i+=6) {  //6 12 18 24 30
        std::bitset<6> hex(0); //543 210

        for(int j=0,k=5; (j<6) & (k>=0); ++j,--k) { //j 0-5 k 5-0
            if(i+j < bits.size()) {
                hex[k] = bits[i+j];

            } else {
                hex[k] = 0;
            }
        }
        returnString << base64chars[hex.to_ulong()] ;

    }

    //add "=" padding if needed
    if(bits.size() % 3 !=0) {
        for(unsigned int i =0; i < bits.size() % 3; ++i) {
            returnString << "=";
        }
    }
    return returnString.str();
}

//! returns string decoded from base64
std::string Base64Converter::decodeFromBase64(const std::string &input)
{
    //return value storage
    returnString.str("");

    //remove ='s
    std::string noEqualsSigns = Utility::removeChar(input, '=');

    //turn b64 chars into corresponding int then that int into bits
    std::vector<bool> bits;
    for(unsigned int i=0; i <noEqualsSigns.size(); ++i) {
        for(int j=0; j < 64; ++j) {
            if(base64chars[j] == noEqualsSigns[i]) {
                std::bitset<6> intBits(j); //543210
                for(int k=5; k>-1; --k) {
                    bits.push_back(intBits[k]);
                }
            }
        }
    }

    //turn bits into bytes
    for(unsigned int i=0; i <bits.size(); i+=8) {
        std::bitset<8> temp(0); //76543210
        for(int j=0,k=7; (j < 8) & (k>=0); ++j, --k) { //j0-7 k7-0
            if(i+8 > bits.size()) {
                return returnString.str();
            } else {
                temp[k] = bits[i+j];
            }
        }
        returnString << static_cast<char>(temp.to_ulong());
    }
    return returnString.str();
}
