
using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;

class Solution {
public:
    int maxProduct(vector<string> &words) {
        // 1或0个返回0
        if (words.size() <= 1) {
            return 0;
        }
        int max = 0;
        ull size = words.size();
        // 使用uint的低26位记录字母是否存在
        vector<uint> check_chars(size, 0);
        for (int i = 0; i < size; ++i) {
            for (const char &ch : words[i]) {
                // 或运算
                check_chars[i] |= 1<<(ch - 'a');
            }
        }

        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < size; ++j) {
                // 检测是否有相同字母
                // 与运算
                if ((check_chars[i] & check_chars[j]) == 0 && words[i].length() * words[j].length() > max) {
                    max = words[i].length() * words[j].length();
                }
            }
        }

        return max;
    }
};