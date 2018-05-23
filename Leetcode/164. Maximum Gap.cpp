class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return 0;
        }
        vector<int> nums_cp(nums);
        sort(nums_cp.begin(), nums_cp.end());
        int result = 0;
        for (int i = 0; i < len - 1; ++i) {
            result = max(nums_cp[i + 1] - nums_cp[i], result);
        }
        
        return result;
    }
};