#include "calculate.hpp"
using namespace std;
string calculateBullAndPgia(string expected, string real) { 
int bull = 0;
int pgia = 0;
for(int i=0; i<expected.length(); i++)
{
    if(expected.at(i) == real.at(i))
    {
      bull++;
    }
    else
    {
      for(int j=i+1; j<expected.length(); j++) {
        if(expected.at(j) == real.at(j))
        {
          pgia++;
        }
      }
    } 
} // End for
string ans = to_string(bull) + "," + to_string(pgia);
return ans;
} // End calculateBullAndPgia