class Solution {
public:
    int reachNumber(int target) {
        target = std::abs(target);
        int i = std::sqrt(2 * target);
        int remain = i * (i + 1) - 2 * target;
        while (remain < 0 || remain % 4 != 0) {
            ++i;
            remain = i * i + i - 2 * target;
        }
        return i;
    }
};
