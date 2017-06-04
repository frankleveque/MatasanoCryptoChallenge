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

#ifndef B64CONVERTER_HPP
#define B64CONVERTER_HPP

#include <string>
#include <sstream>

class Base64Converter
{
private:
    const char *base64chars =  {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};
    std::stringstream returnString;
public:
    Base64Converter();
    ~Base64Converter();
    std::string encodeIntoBase64(const std::string &input);
    std::string decodeFromBase64(const std::string &input);
};
#endif
