#pragma once
#include "Guesser.hpp"
#include <iostream>
#include "calculate.hpp"

using std::string;
/**
 *TheGuesser will find the number by 100 steps the most!
 */
class SmartGuesser: public bullpgia::Guesser {
	string guess() override;
    public:

    void startNewGame(int length){}
    void learn(string reply){}
    
};

