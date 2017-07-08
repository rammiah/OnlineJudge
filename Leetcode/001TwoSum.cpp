class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
  		// 暴力破解不可取啊
        vector<int>sol;
        map<int, int> temp;
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            if (temp.find(nums[i]) == temp.end()) {
                temp[target - nums[i]] = i;
            } 
            else {
                sol.push_back(temp[nums[i]]);
                sol.push_back(i);
                break;
            }
        }
        return sol;
    }
};