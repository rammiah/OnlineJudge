class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int len = S.length();
        
        vector<int> result(len, 30000);
        vector<int> helper;
        for (int i = 0; i < len; ++i) {
            for (int j = i; j < len; ++j) {
                if (S[j] == C) {
                    result[i] = min(j - i, result[i]);
                    break;
                }
            }

            for (int j = i; j >= 0; --j) {
                if (S[j] == C) {
                    result[i] = min(i - j, result[i]);
                    break;
                }
            }
        }

        return result;
    }
};
