/******************************************************************************************************************************
  Given a pair of positive integers, for example, 6 and 110, can this equation 6 = 110 be true?
  The answer is "yes", if 6 is a decimal number and 110 is a binary number.
  Now for any pair of positive integers N1 and N2, your task is to find the radix of one number while that of the other is given.
  Input Specification:
  Each input file contains one test case. Each case occupies a line which contains 4 positive integers:
  N1 N2 tag radix
  Here N1 and N2 each has no more than 10 digits.
  A digit is less than its radix and is chosen from the set {0-9, a-z} where 0-9 represent the decimal numbers 0-9,
  and a-z represent the decimal numbers 10-35. The last number "radix" is the radix of N1 if "tag" is 1, or of N2 if "tag" is 2.
  Output Specification:
  For each test case, print in one line the radix of the other number so that the equation N1 = N2 is true.
  If the equation is impossible, print "Impossible". If the solution is not unique, output the smallest possible radix.
  Sample Input 1:
  6 110 1 10
  Sample Output 1:
  2
  Sample Input 2:
  1 ab 1 2
  Sample Output 2:
  Impossible //Radix 基数
 ********************************************************************************************************************************/
#include <iostream>
#include <string>
using namespace std;
long long Parse(string target, int radix)
{
    long long result = 0;
    for (int i = 0; i < (int)target.length(); ++i)
    {
        result = (target[i] >= 'a' ? target[i] - 'a' + 10 : target[i] - '0') + result * radix;
    }
    return result;
}
long long MinRadix(string target)
{
    long long minRadix = 0, temp = 0;
    for (int i = 0; i < (int)target.length(); ++i)
    {
        temp = target[i] >= 'a' ? target[i] - 'a' + 10 : target[i] - '0';
        if (temp > minRadix)
        {
            minRadix = temp;
        }
    }
    return minRadix + 1;
}
int main(void)
{
    string num1 = "", num2 = "";
    long long intRadix = 0;
    int select = 0;
    bool canEqual = false;
    cin >> num1 >> num2;
    cin >> select >> intRadix;
    long long number = 0;
    number = (select - 1 == 0) ? Parse(num1, intRadix) : Parse(num2, intRadix);
    long long MAX, MIN, temp;
    MAX = number;
    MIN = (select - 1 == 0) ? MinRadix(num2) : MinRadix(num1);
    if (MIN != 1)
    {
        for (long long i = MIN; number >= (temp = Parse(((select - 1 == 0) ? num2 : num1), i));)
        {
            if (number == Parse(((select - 1 == 0) ? num2 : num1), i))
            {
                canEqual = true;
                intRadix = i;
                break;
            }
            if (number != Parse(((select - 1 == 0) ? num2 : num1), MAX))
            {
                if (number != Parse(((select - 1 == 0) ? num2 : num1), MIN))
                {
                    if (number > temp)
                    {
                        MAX = i;
                    }
                    else
                    {
                        MIN = i;
                    }
                    i = (MIN + MAX + 1) / 2;
                }
                else
                {
                    intRadix = MIN;
                    break;
                }
            }
            else
            {
                intRadix = MAX;
                break;
            }
        }
    }
    if (canEqual)
    {
        cout << intRadix << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    return 0;
}
