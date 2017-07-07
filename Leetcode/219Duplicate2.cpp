class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int>dup;
        for (int i = 0; i < nums.size(); ++i) {
            if (dup.find(nums[i]) != dup.end()) {
                if (i - dup[nums[i]] <= k) {
                    return true;
                }
                else {
                    dup[nums[i]] = i;
                }
            }
            else {
                dup[nums[i]] = i;
            }
        }
        return false;
    }
};