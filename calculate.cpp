#include "calculate.hpp"
using namespace std;
string calculateBullAndPgia(string expected, string real) { 
int bull = 0;
int pgia = 0;
int length = expected.length();
int numbers[10] = {0};
for(int i=0; i<expected.length(); i++)
{
    if(expected.at(i) == real.at(i))
    {
      bull++;
    }
    else
    {
      if(numbers[real.at(i) - '0'] ++ < 0) 
      {
        pgia+=1;
      }
      if(numbers[expected.at(i) - '0'] -- > 0) 
      {
        pgia+=1;
      }
    } 
} // End for
string ans = to_string(bull) + "," + to_string(pgia);
return ans;
} // End calculateBullAndPgia