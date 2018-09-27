class Solution {
public:
    // 这个算法太叼了吧？？
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, set<int>> indexs;
        for (int i = 0; i < s.length(); ++i) {
            indexs[s[i]].insert(i);
        }
        int res = 0;
        for (auto &str : words) {
            if (is_sub(str, indexs)) {
                res++;
            }
        }

        return res;
    }

    bool is_sub(string &s, map<char, set<int>> &m) {
        int idx = -1;
        for (int i = 0; i < s.length(); ++i) {
            auto it = m[s[i]].upper_bound(idx);
            if (it == m[s[i]].end()) {
                return false;
            }
            else {
                idx = *it;
            }
        }
        return true;
    }
};