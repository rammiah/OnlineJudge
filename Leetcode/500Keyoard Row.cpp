#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string> &words) {
        string row1 {"qwertyuiopQWERTYUIOP"};
        string row2 {"asdfghjklASDFGHJKL"};
        string row3 {"zxcvbnmZXCVBNM"};
        int nums[256];
        for (char ch : row1) {
            nums[ch] = 1;
        }
        for (char ch : row2) {
            nums[ch] = 2;
        }
        for (char ch : row3) {
            nums[ch] = 3;
        }
        vector<string>sol;
        for (string str : words) {
            bool yes = true;
            for (int j = 0; j < str.length() - 1 && yes; ++j) {
                if (nums[str[j]] != nums[str[j + 1]]) {
                    yes = false;
                }
            }
            if (yes) {
                sol.push_back(str);
            }
        }
        return sol;
    }
};

int main() {


    return 0;
}

