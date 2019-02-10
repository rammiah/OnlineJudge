class Solution {
public:
    int maxProduct(vector<int> &nums) {
        // 最大的积
        if (nums.empty()) {
            return 0;
        }
        if (nums.size() == 1) {
            return nums[0];
        }
        int dp_max = nums[0], dp_min = nums[0], pre_max, pre_min;
        int _max = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            pre_max = dp_max;
            pre_min = dp_min;
            dp_max = max(max(nums[i], nums[i] * pre_max), nums[i] * pre_min);
            dp_min = min(min(nums[i], nums[i] * pre_max), nums[i] * pre_min);
            _max = max(_max, dp_max);
        }
        return _max;
    }
};

