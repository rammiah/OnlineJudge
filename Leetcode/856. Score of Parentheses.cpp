class Solution {
public:
    int scoreOfParentheses(string S) {
        int cnt = 0;
        int res = 0;
        char last = ' ';
        // 只有单独的()可以得分，得分多少与其深度有关
        for (auto &ch : S) {
            if (ch == '(') {
                cnt++;
            }
            else {
                cnt--;
                // 得分
                if (last == '(') {
                    res += 1 << cnt;
                }
            }
            last = ch;
        }

        return res;
    }
};