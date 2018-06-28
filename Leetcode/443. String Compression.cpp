#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int result = 0;
        // 查找重复大于等于两次的字符串抠出来
        char old_ch = chars[0];
        int repeat = 0;
        int idx = 0;
        string num;
        for (auto &ch : chars) {
            if (ch == old_ch) {
                repeat++;
            }
            else {
                result++;
                // 插入结果字符串
                chars[idx++] = old_ch;
                // 检测是否需要插入repeat
                if (repeat > 1) {
                    num = to_string(repeat);
                    for (auto &c : num) {
                        chars[idx++] = c;
                    }
                    result += num.length();
                }
                old_ch = ch;
                repeat = 1;
            }
        }
        // 最后的那个
        result++;
        chars[idx++] = old_ch;
        if (repeat > 1) {
            num = to_string(repeat);
            result += num.length();
            for (auto &ch : num) {
                chars[idx++] = ch;
            }
        }

        return result;
    }
};