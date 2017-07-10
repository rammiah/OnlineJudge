class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
        	if (nums[i] == 0) {
        		int t = i + 1;
        		while (t < nums.size() && nums[t] == 0)
        			t++;
        		if (t == nums.szie() - 1) {
        			return;
        		}
        		nums[i] = nums[t];
        		nums[t] = 0;
        	}
        }
    }
};