#include "hexconverter.hpp"
#include "utility.hpp"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

int main(){
    HexConverter hex;
    
    std::stringstream buffer;
    buffer << std::ifstream("4.txt").rdbuf();

    int highestScore = 0;
    char winningLetter;
    std::string winningText = "";

    std::string temp;
    while(std::getline(buffer, temp)) {

        for(uint8_t i=36; i<=126; ++i){ //for each printable ascii character
            std::string regularString = hex.decodeFromHex(temp);

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
    }

    if(winningText[winningText.length()-1] == '\n'){
        winningText = winningText.substr(0,winningText.length()-1);
    }
    
    std::cout << "\"" << winningText << "\"" << std::endl << "character: " << winningLetter << std::endl << std::endl;

    std::cout << "Press any key to continue..." << std::endl;

    //pause to observe output
    std::cin.get();

}
