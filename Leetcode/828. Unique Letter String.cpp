const int mod = 1E9 + 7;

class Solution {
public:
    int uniqueLetterString(string S) {
        vector<int> ch_idxes[26];
        for (auto &v : ch_idxes) {
            v.push_back(-1);
        }
        int len = S.length();
        for (int i = 0; i < len; ++i) {
            ch_idxes[S[i] - 'A'].push_back(i);
        }
        int ans = 0;
        for (auto &v : ch_idxes) {
            v.push_back(len);
            int size = v.size();
            int c_ans = 0;
            for (int i = 1; i < size - 1; ++i) {
                c_ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
                c_ans %= mod;
            }
            ans += c_ans;
            ans %= mod;
        }
        return ans;
    }
};