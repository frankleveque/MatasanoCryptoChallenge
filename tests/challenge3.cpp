#include "hexconverter.hpp"
#include <string>
#include <iostream>
#include <unordered_map>


int isProbablyEnglishScore(std::string str)
{
    std::unordered_map<char, int> occurrences;
    int score = 0;

    for(auto i=0; i<str.size(); ++i)
    {
        //first letter frequency
        if(str[i]==' ')
            if( (str[i+1] == 't') || (str[i+1] == 'a') || (str[i+1] == 's') )
                    score+=10;
        
        char lower = std::tolower(str[i]);
        occurrences[lower]++;
    }
    //space is more common than e
    if(occurrences[' '] > occurrences['e']) score+=5; 
    
    //letter frequency
    if(occurrences['e'] / str.size() > .10) score+=3;
    if(occurrences['t'] / str.size() > .09) score++;
    if(occurrences['a'] / str.size() > .08) score++;
    if(occurrences['o'] / str.size() > .07) score++;
    if(occurrences['i'] / str.size() > .06) score++;
    if(occurrences['n'] / str.size() > .06) score++;
    if(occurrences['s'] / str.size() > .06) score++;
    if(occurrences['h'] / str.size() > .06) score++;
    if(occurrences['r'] / str.size() > .05) score++;
    if(occurrences['d'] / str.size() > .04) score++;
    if(occurrences['l'] / str.size() > .04) score++;
    return score; 
}

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
        
        for(auto j=0; j<regularString.size(); ++j){ //for each character in string
            regularString[j] = regularString[j] ^ i;
        }
        
        int tempScore = isProbablyEnglishScore(regularString); 
        if(tempScore > highestScore){
            highestScore = tempScore; 
            winningText = regularString;
            winningLetter = i;
        } 
    }

    std::cout << winningText << std::endl << "character: " << winningLetter << std::endl;

    //pause to observe output
    std::cin.get();

}
