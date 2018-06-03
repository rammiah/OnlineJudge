#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
class Solution {
    string simplify(string &str) {
        string res;
        int idx = 0;
        int len = str.length();
        while (str[idx] == '#')idx++;
        for (; idx < len; ++idx) {
            if (str[idx] == '#') {
                if (res.length() > 0) {
                    res.pop_back();
                }
            }
            else {
                res.push_back(str[idx]);
            }
        }
        return res;
    }
public:
    bool backspaceCompare(string S, string T) {
        return simplify(S) == simplify(T);
    }
};