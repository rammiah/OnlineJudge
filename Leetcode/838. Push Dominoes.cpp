#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        // 多米诺骨牌推倒，好有趣的样子
        if (dominoes.length() <= 1) {
            return dominoes;
        }
        bool is_end = false;
        int len = dominoes.length();
        string old_str = dominoes;
        string new_str = dominoes;
        while (!is_end) {
            is_end = true;
            if (old_str[0] == '.') {
                new_str[0] = (old_str[1] == 'L' ? 'L' : '.');
            }
            for (int i = 1; i < len - 1; ++i) {
                if (old_str[i] == '.') {
                    if (old_str[i - 1] != 'R' || old_str[i + 1] != 'L') {
                        if (old_str[i - 1] == 'R') {
                            new_str[i] = 'R';
                            is_end = false;
                        }
                        else if (old_str[i + 1] == 'L') {
                            new_str[i] = 'L';
                            is_end = false;
                        }
                    }
                    
                }
            }
            if (old_str[len - 1] == '.') {
                new_str[len - 1] = (old_str[len - 2] == 'R' ? 'R' : new_str[len - 1]);
            }
            old_str = new_str;
        }
        return old_str;
    }
};