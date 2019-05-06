#pragma once
#include "Guesser.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <list>
#include <math.h>

using std::string;
/**
 *TheGuesser will find the number by 100 steps the most!
 */
class SmartGuesser: public bullpgia::Guesser {
	std::list<std::string> AllOptions;

    std::string shortguess;

    std::string LongGuess;
    int p = 0;


    virtual std::string guess() override;
	virtual void learn(std::string calculateTheAnswer) override;
	virtual void startNewGame(unsigned int length) override;

    std::string LongNumber();
	void learnLongString(std::string calculateLong);
	void startNewGameLong(unsigned int length);
	std::string toints(int,int);

    std::string ShortNumber();
	void learnShortString(std::string calculateShort) ;
	void startNewGameShort(unsigned int length) ;

};