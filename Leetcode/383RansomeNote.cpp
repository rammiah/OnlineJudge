class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length())return false;
        int *chs_ran = new int[26];
        int *chs_mag = new int[26];
        for (int i = 0; i < 26; ++i) {
            chs_ran[i] = chs_mag[i] = 0;
        }
        
        for (int i = 0; i < ransomNote.length(); ++i) {
            ++chs_ran[ransomNote[i] - 'a'];
        }

        for (int i = 0; i < magazine.length(); ++i) {
            ++chs_mag[magazine[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i) {
            if (chs_ran[i] > chs_mag[i]) return false;
        }
        return true;
    }
};