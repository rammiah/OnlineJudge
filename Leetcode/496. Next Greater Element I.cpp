class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> result(findNums.size(), -1);
        for (int i = 0; i < findNums.size(); ++i) {
            // 首先找到这个数字
            int start_idx = 0;
            bool found_num = false;
            for (int j = 0; j < nums.size(); ++j) {
                if (found_num && nums[j] > findNums[i]) {
                    result[i] = nums[j];
                    break;
                }
                else if (nums[j] == findNums[i]) {
                    found_num = true;
                }
            }
        }
        return result;
    }
};