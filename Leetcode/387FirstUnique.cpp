class Solution {
public:
    int firstUniqChar(string s) {
        int *chs = new int[26];
        for (int i = 0; i < 26; ++i) {
            chs[i] = 0;
        }
        
        for (int i = 0; i < s.length(); ++i) {
            ++chs[s[i] - 'a'];
        }
        for (int i = 0; i < s.length(); ++i) {
            if (chs[s[i] - 'a'] == 1) {
                delete[]chs;
                return i;
            }
        }
        delete[] chs;
        return -1;
    }
};