/**
 * @file
 *
 * @author Frank Leveque
 * @brief Solves Matasano Crypto Challenge #1
 * @code
2. Fixed XOR

Write a function that takes two equal-length buffers and produces
their XOR sum.

The string:

 1c0111001f010100061a024b53535009181c

... after hex decoding, when xor'd against:

 686974207468652062756c6c277320657965

... should produce:

 746865206b696420646f6e277420706c6179
 * @endcode
 *
 */

#include "hexconverter.hpp"
#include "utility.hpp"
#include <string>
#include <iostream>


int main()
{
    const std::string original =
    "1c0111001f010100061a024b53535009181c";

    const std::string key =
    "686974207468652062756c6c277320657965";

    HexConverter hex;

    std::cout << "Original String:" << std::endl 
        << original << std::endl << std::endl;

    std::cout << "Original String Decoded From Hex:" << std::endl <<
        hex.decodeFromHex(original) << std::endl << std::endl;
    
    std::cout << "Key:" << std::endl << key << std::endl << std::endl;

    std::cout << "Key Decoded From Hex:" << std::endl << 
        hex.decodeFromHex(key) << std::endl << std::endl;
    
    std::cout << "Final String:" << std::endl << 
        Utility::strXor(hex.decodeFromHex(original), hex.decodeFromHex(key)) 
        << std::endl << std::endl;

    std::cout << "Final String As Hex:" << std::endl << 
        hex.encodeIntoLowerCase(Utility::strXor(hex.decodeFromHex(original), 
                    hex.decodeFromHex(key)));
  
    //pause to observe output
    std::cin.get();
}
