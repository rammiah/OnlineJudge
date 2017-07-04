class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int t = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            t ^= nums[i];
        }
        return t^0;
    }
};
