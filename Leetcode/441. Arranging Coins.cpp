#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int result = 0;
        // 其实这个题和那个等差数列求和的差不多，不过这个是从1开始的，给明了
        while (n >= result) {
            n -= result;
            result++;
        }
        return result;
    }
};