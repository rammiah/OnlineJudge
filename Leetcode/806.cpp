const int max_len = 100;

class Solution {

public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> result(2, 0);
        int lines = 1;
        int line_len = 0;
        int s_len = S.length();
        int ch_len;
        for (int i = 0; i < s_len; ++i) {
            ch_len = widths[S[i] - 'a']; 
            if (ch_len + line_len > 100) {
                line_len = ch_len;
                ++lines;
            } else {
                line_len += ch_len;
            }
        }

        result[0] = lines;
        result[1] = line_len;

        return result;
    }
};