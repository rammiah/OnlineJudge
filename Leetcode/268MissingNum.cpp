class Solution {
public:
    // 数列求和
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
        }
        return nums.size() * (nums.size() + 1) / 2 - sum;
    }
};
