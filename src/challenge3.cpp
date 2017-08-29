#include "hexconverter.hpp"
#include "utility.hpp"
#include <string>
#include <iostream>
#include <unordered_map>



int main()
{

    const std::string hexString =
        "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";

    HexConverter hex;
    int highestScore = 0;
    char winningLetter;
    std::string winningText = "";

    for(uint8_t i=36; i<=126; ++i){ //for each printable ascii character
      std::string regularString = hex.decodeFromHex(hexString);

        for(auto j=0U; j<regularString.size(); ++j){ //for each character in string
            regularString[j] = regularString[j] ^ i;
        }

        int tempScore = Utility::isProbablyEnglishScore(regularString);
        if(tempScore > highestScore){
            highestScore = tempScore;
            winningText = regularString;
            winningLetter = i;
        }
    }

    std::cout << winningText << std::endl << "character: " << winningLetter << std::endl << std::endl;

    std::cout << "Press any key to continue..." << std::endl;

    //pause to observe output
    std::cin.get();

}
