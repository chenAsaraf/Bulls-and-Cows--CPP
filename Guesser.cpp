#include "Guesser.hpp"
using namespace std;


void bullpgia::Guesser::startNewGame(unsigned int length)
{
    this->Stringlength = length;
}

void bullpgia::Guesser::learn(std::string calculateFinalAnswer)
{
    this->finalanswer = calculateFinalAnswer;
}