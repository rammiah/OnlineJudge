class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0];
        for (auto &num : nums) {
            result = min(num, result);
        }
        
        return result;
    }
};