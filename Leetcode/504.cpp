#define BASE 7
class Solution {
public:
    string convertToBase7(int num) {
        // 0特殊照顾
        if (num == 0){
            return "0";
        }
        // 除非是非常引用，不要直接改变传入参数
        int n = num;
        // 转为正数
        n = max(n, -n);
        string res;
        while (n > 0) {
            res = to_string(n % BASE) + res;
            n /= BASE;
        }
        // 负数判断
        if (num < 0) {
            res = "-" + res;
        }
        return res;
    }
};