class Solution {
public:
    // 简直浪费生命啊
    int findPeakElement(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        } 
        int size = nums.size();
        if (nums[0] > nums[1]) {
            return 0;
        }else if (nums[size - 1] > nums[size - 2]) {
            return size - 1;
        }
        for (int i = 1; i < size - 1; ++i) {
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};