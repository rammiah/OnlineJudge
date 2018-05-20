#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        // 多米诺骨牌推倒，好有趣的样子
        // 判断一个牌是否倒下需要知道右的方向
        if (dominoes.length() <= 1) {
            return dominoes;
        }
        bool is_end = false;
        int len = dominoes.length();
        // 处理两侧
        int left = 0;
        for (int i = 0; i < len; ++i) {
            if (dominoes[i] == 'L') {
                for (int j = 0; j < i; ++j) {
                    dominoes[j] = 'L';
                }
            } else if (dominoes[i] == 'R') {
                break;
            }
        }
        int right = len - 1;
        for (int i = len - 1; i >= 0; --i) {
            if (dominoes[i] == 'R') {
                for (int j = len - 1; j > i; --j) {
                    dominoes[j] = 'R';
                }
            } else if (dominoes[i] == 'L') {
                break;
            }
        }
        string old_str = dominoes;
        string new_str = dominoes;
        while (!is_end) {
            is_end = true;
            // 从左到右倒
            // 判断第一个
            if (old_str[0] == '.') {
                new_str[0] = (old_str[1] == 'L' ? 'L' : '.');
            }
            for (int i = 1; i < len - 2; ++i) {
                if (old_str[i] == '.') {
                    if (old_str[i - 1] == 'R' && old_str[i + 1] == 'L') {
                        continue;
                    } else if (old_str[i - 1] == 'R') {
                        is_end = false;
                        new_str[i] = 'R';
                    } else if (old_str[i + 1] == 'L') {
                        new_str[i] = 'L';
                        is_end = false;
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

int main() {
    string s = ".L.R...LR..L..";
    Solution sol;
    cout << sol.pushDominoes(s) << "\n";
    cout << "LL.RR.LLRRLL..";

    return 0;
}