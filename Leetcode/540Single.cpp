class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len / 2; ++i) {
            if (nums[2 * i] != nums[2 * i + 1]) {
                return nums[2 * i];
            }
        }
        return nums[len - 1];

    }

};