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
#include <unordered_map>

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


inline uint32_t isProbablyEnglishScore(const std::string& str)
{
    std::unordered_map<char, int> occurrences;
    int score = 0;

    for(auto i=0U; i<str.size(); ++i){
        //first letter frequency
        if(str[i]==' '){
            if((str[i+1] == 't') || (str[i+1] == 'a') || (str[i+1] == 's'))
                    score+=5;
        }
        char lower = std::tolower(str[i]);
        occurrences[lower]++;
        }

    //space is more common than e
    if(occurrences[' '] > occurrences['e']) score+=3;

    //letter frequency
    if(occurrences['e'] / str.size() >= .10) score+=2;
    if(occurrences['t'] / str.size() >= .09) score++;
    if(occurrences['a'] / str.size() >= .08) score++;
    if(occurrences['o'] / str.size() >= .07) score++;
    if(occurrences['i'] / str.size() >= .06) score++;
    if(occurrences['n'] / str.size() >= .06) score++;
    if(occurrences['s'] / str.size() >= .06) score++;
    if(occurrences['r'] / str.size() >= .06) score++;
    if(occurrences['h'] / str.size() >= .055) score++;
    if(occurrences['d'] / str.size() >= .040) score++;
    if(occurrences['l'] / str.size() >= .035) score++;
    if(occurrences['u'] / str.size() >= .025) score++;

    return score;
}
}
#endif
