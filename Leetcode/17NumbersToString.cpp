#include <iostream>
#include <vector>
#include <string>

using namespace std;


string strs[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

class Solution {
public:

    void calcu(vector<string>&sol, vector<string>&temp, string str, int index) {
        if (index >= temp.size())return;
        if (index == temp.size() - 1){
            for (int i = 0; i < temp[index].length(); ++i) {
                sol.push_back(str + temp[index].at(i));
            }
        } else{
            for (int i = 0; i < temp[index].length(); ++i) {
                calcu(sol, temp, str + temp[index].at(i), index + 1);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string>temp;
        for (auto i = 0u; i < digits.length(); ++i) {
            temp.push_back(strs[digits[i] - '0']);
        }
        vector<string>sol;
        calcu(sol, temp, "", 0);
        return sol;
    }
};

int main() {
    Solution sol;

    auto strs = sol.letterCombinations("23");
    for (int i = 0; i < strs.size(); ++i) {
        cout << strs.at(i) << endl;
    }


    return 0;
}