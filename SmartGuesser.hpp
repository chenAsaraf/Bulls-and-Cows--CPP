#pragma once
#include "Guesser.hpp"
using std::string;
#include <iostream>

/**
 *TheGuesser will find the number by 100 steps the most!
 */
class SmartGuesser: public bullpgia::Guesser {
	string guess() override;
    public:

    void startNewGame(int length){}
    void learn(string reply){}
    
};

