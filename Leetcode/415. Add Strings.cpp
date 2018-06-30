#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

static const string rep[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
class Solution {
public:
    string addStrings(string num1, string num2) {
        int idx1 = num1.length() - 1, idx2 = num2.length() - 1;
        string result;
        // 两个非负数，还行
        int a = 0, b = 0, sum = 0;
        while (idx1 >= 0 || idx2 >= 0 || sum > 0) {
            a = idx1 >= 0 ? num1[idx1--] - '0' : 0;
            b = idx2 >= 0 ? num2[idx2--] - '0' : 0;
            sum += a + b;
            result.append(rep[sum%10]);
            sum /= 10;
        }
        std::reverse(result.begin(), result.end());

        return result;
    }
};