#include <vector>
#include <string>

using namespace std;

class Solution {
    bool backtracking(string S, string has, int one, int two, vector<int> &result) {
        string new_str = has + to_string(one + two);
        if (S.length() < new_str.length()) {
            return false;
        }
        else if (S == new_str) {
            result.push_back(one + two);
            return true;
        }
        if (S.find(new_str) == 0) {
            result.push_back(one + two);
            if (backtracking(S, new_str, two, one + two, result)) {
                return true;
            }
            else {
                // 其实这个pop也没啥用
                // result.pop_back();
                return false;
            }
        }
        return false;
    }
public:
    vector<int> splitIntoFibonacci(string S) {
        // 查看S能否分成fibonacci-like的数组
        // 进行尝试，首先确定前两个数字，必须最少3个数字
        std::vector<int> result;
        int first, second;
        result.clear();
        // 典型回溯法
        for (int i = 1; i < S.length() && i < 13; ++i) {
            for (int j = i + 1; j < S.length() && j - i < 13; ++j) {
                // 数字太大会抛error，还得限制位数，服了
                // 直接返回错误结果我也没问题啊
                if (stoll(S.substr(0, i)) > INT_MAX || stoll(S.substr(i, j - i)) > INT_MAX) {
                    break;
                }
                result.push_back(stoi(S.substr(0, i)));
                result.push_back(stoi(S.substr(i, j - i)));
                // 同一个地方卡那么多次，我也是服了
                if (backtracking(S, to_string(result[0]) + to_string(result[1]), result[0], result[1], result)) {
                    return result;
                }
                else {
                    result.clear();
                }
            }
        }
        return result;
    }
};