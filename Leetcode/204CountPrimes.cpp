class Solution {
public:
    int countPrimes(int n) {
        // 一个一个查果然靠不住
        int* nums = new int[n];
        for (int i = 0; i < n; ++i) {
            nums[i] = 1;
        }
        int count = 0;
        if (n > 2)++count;
        for (int i = 3; i < n; ++i, ++i) {
            if (nums[i] == 1) {
                ++count;
                for (int times = 2 * i; times < n; times += i) {
                    nums[times] = 0;
                }
            }
        }
        delete[] nums;
        return count;
    }
};