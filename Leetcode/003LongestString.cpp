//
// Created by yaning on 17-6-1.
//
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int maxLength = 0;
        int length = 0;
        int check[255] = { 0, };
        for (; right < s.length(); right++) {
            if (check[s[right]] == 1) {
                for (; s[left] != s[right]; left++) {
                    check[s[left]] = 0;
                    length--;
                }
                left++;
            } else {
                check[s[right]] = 1;
                length++;
                if (length > maxLength) {
                    maxLength = length;
                }
            }
        }

        return maxLength;
    }
};

int main() {

    Solution sol;

    cout << sol.lengthOfLongestSubstring("12342543921");

    return 0;
}
