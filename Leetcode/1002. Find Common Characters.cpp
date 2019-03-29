int counter[256][105];

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> res;
        memset(counter, 0, sizeof(counter));
        int len = A.size();
        for (int i = 0;  i < A.size(); ++i) {
            for (auto &c : A[i]) {
                counter[c][i]++;
            }
        }
        // 查找
        for (auto c = 'a'; c <= 'z'; ++c) {
            int cnt = INT_MAX;
            for (int i = 0; i < len; ++i) {
                cnt = min(cnt, counter[c][i]);
            }
            // 插入到res
            string s = " ";
            s[0] = c;
            for (int i = 0; i < cnt; ++i) {
                res.push_back(s);
            }
        }
        
        return res;
    }
};
