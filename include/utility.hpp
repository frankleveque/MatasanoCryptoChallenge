/**
 * @file
 *
 * @author Frank Leveque
 * @brief Useful inline functions for the Matasano Crypto Challenge
 *
 */

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <cstring>

namespace Utility
{

//! returns string with char removed
inline std::string removeChar(std::string str, char ch)
{
    std::stringstream ss;
    ss.str("");
    for(unsigned int i=0; i < str.size(); ++i)
    {
        if(str[i] != ch)
            ss << str[i];
    }
    return (std::string)ss.str();
}

//! fixed xor of two strings
inline std::string strXor(std::string &a, std::string &b)
{
    if(a.length() != b.length()){
    return "Error";
    }

    std::string temp;
    for(unsigned i = 0; i < a.length(); ++i){
        temp += a[i] ^ b[i];
    }
    return temp;
}

//! fixed xor of two strings
inline std::string strXor(std::string &&a, std::string &&b)
{
    if(a.length() != b.length()){
    return "Error";
    }

    std::string temp;
    for(unsigned i = 0; i < a.length(); ++i){
        temp += a[i] ^ b[i];
    }
    return temp;
}

inline std::string bufferXor(char const* a, char const* b)
{

    char* temp;

    for(unsigned i = 0; i < strlen(a); ++i){
        temp += a[i] ^ b[i];
    }
    return temp;
}
}
#endif
