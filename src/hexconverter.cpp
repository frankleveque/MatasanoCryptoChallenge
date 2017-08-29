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
#include <exception>


HexConverter::HexConverter(){

    //decode
    hexMap['0'] = 0;
    hexMap['1'] = 1;
    hexMap['2'] = 2;
    hexMap['3'] = 3;
    hexMap['4'] = 4;
    hexMap['5'] = 5;
    hexMap['6'] = 6;
    hexMap['7'] = 7;
    hexMap['8'] = 8;
    hexMap['9'] = 9;
    hexMap['a'] = 10;
    hexMap['b'] = 11;
    hexMap['c'] = 12;
    hexMap['d'] = 13;
    hexMap['e'] = 14;
    hexMap['f'] = 15;
    hexMap['A'] = 10;
    hexMap['B'] = 11;
    hexMap['C'] = 12;
    hexMap['D'] = 13;
    hexMap['E'] = 14;
    hexMap['F'] = 15;

    //encode
    hexMap[0] = '0';
    hexMap[1] = '1';
    hexMap[2] = '2';
    hexMap[3] = '3';
    hexMap[4] = '4';
    hexMap[5] = '5';
    hexMap[6] = '6';
    hexMap[7] = '7';
    hexMap[8] = '8';
    hexMap[9] = '9';
    hexMap[10] = 'a';
    hexMap[11] = 'b';
    hexMap[12] = 'c';
    hexMap[13] = 'd';
    hexMap[14] = 'e';
    hexMap[15] = 'f';

    //other
    hexMap[':'] = 'a';
    hexMap[';'] = 'b';
    hexMap['<'] = 'c';
    hexMap['='] = 'd';
    hexMap['>'] = 'e';
    hexMap['?'] = 'f';


}


void HexConverter::setLowerCase(){
    hexMap[':'] = 'a';
    hexMap[';'] = 'b';
    hexMap['<'] = 'c';
    hexMap['='] = 'd';
    hexMap['>'] = 'e';
    hexMap['?'] = 'f';
    hexMap[10] = 'a';
    hexMap[11] = 'b';
    hexMap[12] = 'c';
    hexMap[13] = 'd';
    hexMap[14] = 'e';
    hexMap[15] = 'f';
}

void HexConverter::setUpperCase(){
    hexMap[':'] = 'A';
    hexMap[';'] = 'B';
    hexMap['<'] = 'C';
    hexMap['='] = 'D';
    hexMap['>'] = 'E';
    hexMap['?'] = 'F';
    hexMap[10] = 'A';
    hexMap[11] = 'B';
    hexMap[12] = 'C';
    hexMap[13] = 'D';
    hexMap[14] = 'E';
    hexMap[15] = 'F';
}

//! hex values returned
std::string HexConverter::encodeIntoHex(uint8_t input){

    return encode(input);
}

//! hex values returned
std::string HexConverter::encodeIntoHex(const std::string &input){

    return encode(input);
}

//! where actual encoding to hex takes place
std::string HexConverter::encode(uint8_t input){
    std::stringstream ss;


    std::bitset<8> temp(input);
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

    if(firstPart.to_ulong() > 0){
        ss << hexMap[firstPart.to_ulong()];
    }

    ss << hexMap[secondPart.to_ulong()];
    return ss.str();
}

//! where actual encoding to hex takes place
std::string HexConverter::encode(const std::string& input){
    std::stringstream ss;
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
        if(firstPart.to_ulong() > 0){
            ss << hexMap[firstPart.to_ulong()];
        }
        ss << hexMap[secondPart.to_ulong()];
    }
    return ss.str();
}


char HexConverter::decode(char nibble){
    return hexMap.at(nibble);
}

char HexConverter::decode(char a, char b){
    std::bitset<8> temp;
    std::bitset<4> first(decode(a));
    std::bitset<4> second(decode(b));
    temp[7] = first[3];
    temp[6] = first[2];
    temp[5] = first[1];
    temp[4] = first[0];
    temp[3] = second[3];
    temp[2] = second[2];
    temp[1] = second[1];
    temp[0] = second[0];

    return temp.to_ulong();
}

//! convert from hex to ascii
std::string HexConverter::decodeFromHex(const std::string &input){
    std::stringstream ss;
    std::string temp;
    if(input.size() == 0){
        return "";
    }else if(input.size() == 1){
        ss << std::to_string(decode(input[0]));
    }else{
        for(auto i=0U; i<input.size(); i+=2) {
            ss << decode(input[i], input[i+1]);
            temp = ss.str();
        }
    }
    return ss.str();

}



std::string HexConverter::decodeFromHex(uint8_t input){
    std::stringstream ss;

    ss<< hexMap[std::atoi(std::to_string(input).c_str())];
    return ss.str();
}
