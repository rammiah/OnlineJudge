class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        // roll b to check if B is startswith A
        int len = B.size();
        string str;
        int max = B.size() / A.size();
        for (int i = 0; i < max; ++i) {
            str += A;
        }
        for (int i = max; i <= max + 2;++i) {
            if (str.find(B) != -1) {
                return i;
            }
            str += A;
        }
        
        return -1;
    }
};
