#include "SmartGuesser.hpp"
using namespace std;

string SmartGuesser::guess(){
    string answer;
    if(length > 7) {
        answer = SmartGuesser::LongNumber();
    }
    else {
        answer = SmartGuesser::ShortNumber();
    }
    return answer;
}

void SmartGuesser::learn(std::string calculateTheAnswer) {
    if(length > 7) {
        SmartGuesser::learnLongString(calculateTheAnswer);
    }
    else {
        SmartGuesser::learnShortString(calculateTheAnswer);
    }
}

void SmartGuesser::startNewGame(unsigned int length) {
    if(length < 0 ) throw std::invalid_argument("length cannot be smaller then 0");
    if(length > 7) {
        SmartGuesser::startNewGameLong(length);
    }
    else {
        SmartGuesser::startNewGameShort(length);
    }
}

/////////LONG FUNCTIONS//////////
string SmartGuesser::LongNumber() {
    string ans = "" ;
    if(LongGuess.length() != this->length) {
	    ans = this->toints(p,this->length);
	    p++;
    }
    else
    {
        ans = AllOptions.front();
        AllOptions.pop_front();
        LongGuess = ans;
    }
    return ans;
}

void SmartGuesser::learnLongString(std::string calculateLong){
    SmartGuesser::Guesser::learn(calculateLong);
    if(LongGuess.length() < this->length) { 
        string psik = ",";
        string sign = this->finalanswer.substr(0, this->finalanswer.find(psik)); // sign is the bull results
        int Bulls = stoi(sign);
        if( Bulls > 0) {
                for(int i=0; i<Bulls; i++) {
                    LongGuess += to_string(p-1);
                }
        } // End Bull > 0 IF
        if(LongGuess.length() == this->length)
        {
            sort(LongGuess.begin(), LongGuess.end());
            AllOptions.push_front(LongGuess); // we put the guess in our list
            while(next_permutation(LongGuess.begin(), LongGuess.end())) {
                AllOptions.push_front(LongGuess); // again we push to the list
            }
        }
    }
    else
    {
        list<string>::iterator iter = AllOptions.begin();
        while(iter != AllOptions.end())
        {
            string current_perm = *iter;
            int equals = calculateBullAndPgia(LongGuess,current_perm).compare(this->finalanswer);
            if(equals != 0)
            {
                iter = AllOptions.erase(iter);
            }
            else iter++;
        }
    }
}

void SmartGuesser::startNewGameLong(unsigned int length){
    SmartGuesser::Guesser::startNewGame(length);
	p = 0;
	LongGuess.clear();
    AllOptions.clear();
}



////////SHORT FUNCTIONS//////////
string SmartGuesser::ShortNumber() {
	string r="";
	if (AllOptions.size()==pow(10,length)) {
		for (uint i=0; i < this->length; ++i) {
			char c = '0' + i+1;
			r += c;
		}
		shortguess = r;
		return r;
	}
	//random choice from all_option after filtering
	list<string>::iterator iter = AllOptions.begin();
	if (AllOptions.size()>1)
		advance(iter,rand()%(AllOptions.size()-1));
	shortguess = *iter;
    return shortguess;
}

void SmartGuesser::learnShortString(std::string calculateShort){
    list<string>::iterator iter = AllOptions.begin();
	while (iter != AllOptions.end()) {
        	string BullandPgiaCurrAnswer = calculateBullAndPgia(*iter, shortguess); 
	  	if (calculateShort.compare(BullandPgiaCurrAnswer)!=0){
			iter=AllOptions.erase(iter);
		}
		else iter++;
    }
}

void SmartGuesser::startNewGameShort(unsigned int length){
    AllOptions.clear();
    shortguess.clear();
	bullpgia::Guesser::startNewGame(length);
	unsigned int max = pow(10,length);

	for (unsigned int i=0;i<max;i++){
		stringstream ss;
		ss << setw(length) << setfill('0') << i;
		string str = ss.str();
		AllOptions.push_front(str);
    }
}

////////string to number func/////
string SmartGuesser::toints(int num, int num2) {
	string ans;
	for(int i=0; i<num2; i++) { 
        ans += to_string(num);
    }
	return ans;
}