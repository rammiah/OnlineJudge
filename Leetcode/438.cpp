class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int s_len = s.length();
        int p_len = p.length();
        vector<int> ch_cnts(26, 0);
        vector<int> p_chs(26, 0);
        vector<int> res;
        // 长度满足的关系s_len >= p_len
        if (s_len < p_len) {
            return res;
        }
        for (int i = 0; i < p_len; ++i) {
            ++p_chs[p[i] - 'a'];
            ++ch_cnts[s[i] - 'a'];
        }
        
        if (p_chs == ch_cnts) {
            res.push_back(0);
        }

        for (int i = 0; i < s_len - p_len; ++i) {
            --ch_cnts[s[i] - 'a'];
            ++ch_cnts[s[i + p_len] - 'a'];
            if (p_chs == ch_cnts) {
                res.push_back(i + 1);
            }
        }

        return res;
    }
};