class Solution {
public:
    bool increasingTriplet(const vector<int> &nums) {
        // LIS的简化版吧，有个更复杂的，n*log(n)，这个是n^2
        // 原来是在学DP的时候看到的，挺巧妙的算法
        int incs[3] = {INT_MAX, INT_MAX, INT_MAX};
        for (const auto &n : nums) {
            // 写入到incs
            int idx = -1;
            // 这个其实类似插入排序的一个步骤，只有插入
            // 可以使用二分查找插入位置，大于等于插入数字的最小位置，达到n*log(n)
            for (int i = 2; i >= 0; i--) {
                if (n <= incs[i]) {
                    idx = i;
                }
            }
            if (idx != -1) {
                incs[idx] = n;
            }
            if (idx == 2) {
                return true;
            }
        }
        return incs[2] != INT_MAX;
    }
};
