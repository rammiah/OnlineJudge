int nums[60];

class Solution {
public:
    int integerBreak(int n) {
        memset(nums, 0, sizeof(nums));
        nums[0] = 0;
        nums[1] = 1;
        for (int i = 2; i <= n; ++i) {
            nums[i] = i - 1;
            for (int j = 1; j <= i; ++j) {
                nums[i] = std::max(j * nums[i - j], nums[i]);
                nums[i] = std::max(j * (i - j), nums[i]);
            }
            // std::cout << i << ' ' << nums[i] << std::endl;
        }
        
        return nums[n];
    }
};