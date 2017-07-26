class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        int left = 0;
        int right = nums.size() - 1;
        int diff = 0;
        for (int i = 1; i < nums.size() - 1; ++i) {
            left = 0;
            right = nums.size() - 1;
            while (left < i && right > i) {
                diff = nums[left] + nums[right] + nums[i] - target;
                if (abs(diff) < abs(minDiff)) {
                    minDiff = diff;
                }
                if (diff < 0) {
                    left++;
                } else if (diff > 0) {
                    right--;
                } else {
                    return target;
                }
            }
        }
        return target + minDiff;
    }
};