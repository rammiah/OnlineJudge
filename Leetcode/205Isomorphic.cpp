class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	// 开始以为只有26个字幕┭┮﹏┭┮
    	const int base = 256;
        if (s.length() != t.length())return false;
        int*char_s = new int[base];
        int*char_t = new int[base];
        for (int i = 0; i < base; ++i) {
        	char_t[i] = char_s[i] = -1;
        }
        int count = 0; 		// 出现的不重复字母数
        for (int i = 0; i < s.length(); ++i) {
 
           	if (char_s[s[i]] == -1 && char_t[t[i]] == -1){
           		char_s[s[i]] = char_t[t[i]] = ++count;
           	} else if (char_s[s[i]] != char_t[t[i]]) {
           		return false;
           	}
        }
        return true;
    }
};