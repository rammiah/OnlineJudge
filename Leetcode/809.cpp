#include <vector>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Solution {
    bool match(const string &S, const string &word) {
        if (S == word) {
            return true;
        }
        int w_len = word.length();
        int s_len = S.length();
        // 长度关系必须满足s不比w长
        char s_str[105] = {0};
        strcpy(s_str, S.c_str());
        char w_str[300] = {0};
        strcpy(w_str, word.c_str());
        if (s_len > w_len) {
            return false;
        }
        int w_idx = 0, s_idx = 0;
        while (s_idx < s_len && w_idx < w_len) {
            if (s_str[s_idx] != w_str[w_idx]) {
                return false;
            } else {
                // 此处只有一个字符
                if (s_str[s_idx] != s_str[s_idx + 1]) {
                    int len = 1;
                    while (w_str[w_idx + len] == s_str[s_idx]) {
                        // 找到不是的
                        // 记录有多长
                        ++len;
                    }
                    // 长度为2表示违反规则
                    if (len == 2) {
                        return false;
                    }
                    w_idx += len;
                    // s向后移动
                    ++s_idx;
                } else {
                    // s有好几个字符相连
                    // 先记录长度
                    int len = 0;
                    while (S[s_idx] == S[s_idx + len]) {
                        len++;
                    }
                    // 这个时候的word里面必须连续多个比S的长
                    for (int i = 0; i < len; ++i) {
                        if (word[w_idx + i] != S[s_idx]) {
                            return false;
                        }
                    }
                    while (word[w_idx] == S[s_idx]) {
                        ++w_idx;
                    }
                    s_idx += len;
                }
            }
        }

        return !(s_idx < s_len || w_idx < w_len);

    }
public:
    int expressiveWords(string S, vector<string>& words) {
        int cnt = 0;
        for (const auto &word : words) {
            if (match(word, S)) {
                ++cnt;
            }
        }

        return cnt;
    }

};

int main() {
    Solution sol;
    std::vector<string> strs = {"hello", "hi", "helo"};
    std::cout << sol.expressiveWords("hello", strs) << "\n";

    return 0;
}

/*
Example:
Input: 
S = "heeellooo"
words = ["hello", "hi", "helo"]
Output: 1
Explanation: 
We can extend "e" and "o" in the word "hello" to get "heeellooo".
We can't extend "helo" to get "heeellooo" because the group "ll" is not extended.
*/