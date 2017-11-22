/*
Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]
*/
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

class Solution {
private:
    // 检测范围是否正确
    inline bool valid(const long long &value) {
        return value <= 255 && value >= 0;
    }

public:
    vector<string> restoreIpAddresses(const string &s) {
        vector<string> result;
        // 如果长度不够或者太长了都不可能
        if (s.length() < 4 || s.length() > 12) {
            return result;
        }
        
        long long a, b, c, d;// 标记那三个点的位置。
        // 放入结果字符串
        char chs[17];
        // 搜索点所有可能的排列
        for (int i = 1; i < s.length(); ++i) {
            for (int j = i + 1; j < s.length(); ++j) {
                for (int k = j + 1; k < s.length(); ++k) {
                    // 转换为数字
                    a = stoll(s.substr(0, i));
                    b = stoll(s.substr(i, j - i));
                    c = stoll(s.substr(j, k - j));
                    d = stoll(s.substr(k, s.length() - k));
                    // 检测是否接回去还是原来的
                    string sum = to_string(a) + to_string(b) + to_string(c) + to_string(d);
                    if (valid(a) && valid(b) && valid(c) && valid(d) && sum == s) {
                        // 16 + "\0"
                        
                        // 虽然effective stl上面给了我好几个做法
                        snprintf(chs, 17,"%lld.%lld.%lld.%lld", a, b, c, d);
                        result.push_back(string(chs));
                    }
                }
            }
        }
        // 返回结果
        return result;
    }
};

int main() {
    Solution sol;

    for (auto &t : sol.restoreIpAddresses("25525511135")) {
        cout << t << "\n";
    }
    return 0;
}
