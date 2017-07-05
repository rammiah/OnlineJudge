class Solution {
	int base = 26;
public:
	// 类似数字进位
    int titleToNumber(string s) {
    	int sol = 0;
        for (int i = 0; i < s.size(); ++i) {
        	sol = sol * base + s[i] - 'A' + 1;
        }
        return sol;
    }
};