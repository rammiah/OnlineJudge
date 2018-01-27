/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return
[
  ["aa","b"],
  ["a","a","b"]
]
*/


class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> tmp;
        get_partion(res, tmp, 0, s);
        return res;
    }

    void get_partion(vector<vector<string>> &res, vector<string> &tmp, int pos, string &s) {
        // 检测完毕，加入最终结果
        if (pos == s.size()){
            res.push_back(tmp);
            return;
        }
        auto t = s.size();
        for (int i = pos; i < t; ++i) {
            // 回溯法
            if (is_palindrome(s, pos, i)) {
                tmp.push_back(s.substr(pos, i - pos + 1));
                get_partion(res, tmp, i + 1, s);
                // 记得pop掉最后的那个
                tmp.pop_back();
            }
        }
    }
    // 检测是否为回文字符串
    bool is_palindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};