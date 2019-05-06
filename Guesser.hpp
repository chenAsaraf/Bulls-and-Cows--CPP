#pragma once
#include <iostream>
#include "calculate.hpp"

namespace bullpgia {
    class Guesser {
    protected:
        unsigned int Stringlength;
        std::string finalanswer; // how many bulls and pgias are there.
        

    public:
    //virtual methods:
        // Returns a string
        virtual std::string 
        guess() = 0;

        //this method is starting a new game with length
        virtual void startNewGame(unsigned int length);
    
        //figures out what the finalanswer is.(how many bulls and pgias are there.)
        virtual void learn(std::string calculateFinalAnswer);
    };
}