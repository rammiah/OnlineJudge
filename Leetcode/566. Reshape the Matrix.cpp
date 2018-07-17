class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int row = nums.size(), col = nums[0].size();
		if (row * col != r * c) {
			return nums;
		}
		vector<vector<int>> result(r, vector<int>(c));
		int idx = 0;
		int sum = r * c;
		while (idx < sum) {
			result[idx / c][idx % c] = nums[idx / col][idx % col];
			++idx;
		}
		return result;
	}
};
