class Solution {
	int temp_nums[10005];
public:
	vector<int> findErrorNums(vector<int>& nums) {
		// 搞不懂有什么意义
		memset(temp_nums, 0, sizeof(temp_nums));
		int sum = 0, t = nums.size();
		int dup = nums[0];
		for (int i = 0; i < nums.size(); ++i) {
			if (temp_nums[nums[i] - 1] == 1) {
				dup = nums[i];
			}
			else {
				temp_nums[nums[i] - 1]++;
			}
			sum += nums[i];
		}
		return { dup, t * (t + 1) / 2 + dup - sum };
	}
};
