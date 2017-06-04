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

#ifndef HEXCONVERTER_HPP
#define HEXCONVERTER_HPP

#include <vector>
#include <string>
#include <sstream>

class HexConverter
{
private:
    std::vector<char> hexTable;
    std::string encoder(const std::string &input);
    std::stringstream ss;
    int findHex(char hexval);
public:
    HexConverter();
    ~HexConverter();
    std::string encodeIntoLowerCase(const std::string &input);
    std::string encodeIntoUpperCase(const std::string &input);
    std::string decodeFromHex(const std::string &input);
//std::string decodeFromHex(char const* input);

};
#endif
