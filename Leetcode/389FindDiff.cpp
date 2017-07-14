class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;
        for (int i = 0; i < s.length(); ++i) {
            ch ^= s[i];
            ch ^= t[i];
        }
        ch ^= t[t.length() - 1];
        return ch;
    }
};