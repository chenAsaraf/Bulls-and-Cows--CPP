#pragma once
#include "Guesser.hpp"
using std::string;
#include <iostream>

/**
 *TheGuesser will find the number by 100 steps the most!
 */
class TheGuesser: public bullpgia::Guesser {
	string guess() override;
    public:

    void startNewGame(uint length){}
    void learn(string reply){}
    
};

