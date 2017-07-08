class Solution {
public:
    // 只能说佩服，从中间向两边拓展，
    string longestPalindrome(string s) {
        int result = 0, len = 0;
        for (int i = 0; i < s.size(); ) {
            int start = i, end = i;
            while (end < s.size() && s[end] == s[end + 1])
                end++;
            i = end + 1;
            while (start >= 0 && end < s.size() && s[start] == s[end]) {
                start--;
                end++;
            }
            if (end - start - 1 > len) {
                result = start + 1;
                len = end - start - 1;
            }
        }

        return s.substr(result, len);
    }
};
