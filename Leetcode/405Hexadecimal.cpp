class Solution {
public:
    string toHex(int num) {
        // 为什么go版本的不需要判断0？？？
        if (num == 0)return "0";
        char chs[] = "0123456789abcdef";
        string result;
        unsigned unum = (unsigned)num;
        while(unum > 0) {
            result = chs[unum % 16] + result;
            unum /= 16;
        }

        return result;
    }
};
