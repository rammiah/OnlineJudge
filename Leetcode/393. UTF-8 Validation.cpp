class Solution {
    static int len_of_1(int x) {
        static std::bitset<8> bits;
        bits = x;
        int res = 0;
        while (x & 0b10000000) {
            x <<= 1;
            ++res;
        }
        return res;
    }

public:
    bool validUtf8(vector<int> &data) {
        // nb
        for (int i = 0; i < data.size(); ++i) {
            if (data[i] & 0b10000000) {
                // i需要加一点
                int len = len_of_1(data[i]) - 1;
                if (len < 1 || len >= 4 || i + len >= data.size()) {
                    return false;
                }
                for (int j = i + 1; j <= i + len; ++j) {
                    if ((data[j] & 0b11000000) != 0b10000000) {
                        return false;
                    }
                }
                i += len;
            }
        }
        return true;
    }
};

