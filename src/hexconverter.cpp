/*
HexConverter - Tool for converting into and from hexadecimal
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

#include "hexconverter.hpp"
#include <bitset>
#include <iostream>
#include <string>
#include <cctype>
#include <cassert>



HexConverter::HexConverter()
{
    //preliminary population of hextable
    hexTable.push_back('0');
    hexTable.push_back('1');
    hexTable.push_back('2');
    hexTable.push_back('3');
    hexTable.push_back('4');
    hexTable.push_back('5');
    hexTable.push_back('6');
    hexTable.push_back('7');
    hexTable.push_back('8');
    hexTable.push_back('9');
    hexTable.push_back('a');
    hexTable.push_back('b');
    hexTable.push_back('c');
    hexTable.push_back('d');
    hexTable.push_back('e');
    hexTable.push_back('f');
}

HexConverter::~HexConverter()
{
}

//! hex values returned as lowercase
std::string HexConverter::encodeIntoLowerCase(const std::string &input)
{
    hexTable[10] = 'a';
    hexTable[11] = 'b';
    hexTable[12] = 'c';
    hexTable[13] = 'd';
    hexTable[14] = 'e';
    hexTable[15] = 'f';

    return encoder(input);
}

//! hex values returned as uppercase
std::string HexConverter::encodeIntoUpperCase(const std::string &input)
{
    hexTable[10] = 'A';
    hexTable[11] = 'B';
    hexTable[12] = 'C';
    hexTable[13] = 'D';
    hexTable[14] = 'E';
    hexTable[15] = 'F';

    return encoder(input);
}

//! where actual encoding to hex takes place
std::string HexConverter::encoder(const std::string &input)
{
    ss.str("");
    for(unsigned int i=0; i<input.size(); ++i) {
        std::bitset<8> temp(input[i]);
        std::bitset<4> firstPart;
        std::bitset<4> secondPart;
        firstPart[3] = temp[7];
        firstPart[2] = temp[6];
        firstPart[1] = temp[5];
        firstPart[0] = temp[4];
        secondPart[3] = temp[3];
        secondPart[2] = temp[2];
        secondPart[1] = temp[1];
        secondPart[0] = temp[0];

        ss << hexTable[firstPart.to_ulong()];
        ss << hexTable[secondPart.to_ulong()];
    }
    return ss.str();
}

//! find a value in hextable and return its position
int HexConverter::findHex(char hexval)
{
    for(unsigned int i=0; i<hexTable.size(); ++i) {
        if(std::tolower(hexTable[i]) == std::tolower(hexval)) {
            return i;
        }
    }
    assert(false);
    return -1;
}

//! convert from hex to ascii
std::string HexConverter::decodeFromHex(const std::string &input)
{
    ss.str("");
    std::vector<bool> bits;

    for(unsigned int i=0; i<input.size(); ++i) {
        std::bitset<4> holding(findHex(input[i]));
        for(int j=3; j>=0; --j) {
            bits.push_back(holding[j]);
        }
    }
    bits.shrink_to_fit();
    while(bits.size() < 8)
        bits.insert(bits.begin(), 1, 0);
    
    for(unsigned int k=0; k<bits.size(); k+=8) {
        std::bitset<8> whole(0);

        whole[7] = bits[k+0];
        whole[6] = bits[k+1];
        whole[5] = bits[k+2];
        whole[4] = bits[k+3];
        whole[3] = bits[k+4];
        whole[2] = bits[k+5];
        whole[1] = bits[k+6];
        whole[0] = bits[k+7];
        //ss << static_cast<uint32_t>(whole.to_ulong());

        ss << whole.to_ulong();
    }
    return ss.str();
}


/*
//! convert from hex to ascii
std::string HexConverter::decodeFromHex(char const* input)
{
    size_t current_size = 0;

    char buffer [0];
    
    std::vector<bool> bits;

    for(unsigned int i=0; i<strlen(input); ++i) {
        std::bitset<4> holding(findHex(input[i]));
        for(int j=3; j>=0; --j) {
            buffer[current_size++] = holding[j];
        }
    }

    for(unsigned int k=0; k<current_size; ++k) {
        std::bitset<8> whole(0);

        whole[7] = bits[k+0];
        whole[6] = bits[k+1];
        whole[5] = bits[k+2];
        whole[4] = bits[k+3];
        whole[3] = bits[k+4];
        whole[2] = bits[k+5];
        whole[1] = bits[k+6];
        whole[0] = bits[k+7];

        ss<< static_cast<char>(whole.to_ulong());
    }
    return ss.str();
}*/
