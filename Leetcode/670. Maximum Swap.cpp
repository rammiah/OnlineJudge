class Solution {
public:
    int maximumSwap(int num) {
        if (num <= 10) {
            return num;
        }
        string str = to_string(num);
        // 感觉就是对数字排序啊
        for (int i = 0; i < str.length(); ++i) {
            int max_idx = i;
            for (int j = str.length() - 1; j > i; --j) {
                if (str[j] > str[max_idx]) {
                    max_idx = j;
                }
            }
            if (max_idx != i) {
                swap(str[i], str[max_idx]);
                break;
            }
        }

        return stoi(str);
    }
};