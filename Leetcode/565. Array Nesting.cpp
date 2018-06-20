class Solution {
	int max_len;
	int get_len(int idx, vector<int> &nums, vector<bool> &visited, vector<int> &lens) {
		if (visited[idx]) {
			return lens[idx];
		}
		if (idx == nums[idx]) {
			visited[idx] = true;
			lens[idx] = 1;
			return 1;
		}

		visited[idx] = true;
		lens[idx] = 1 + get_len(nums[idx], nums, visited, lens);
		return lens[idx];
	}
public:
	int arrayNesting(vector<int>& nums) {
		max_len = 0;
		int size = nums.size();
		vector<bool> visited(size, 0);
		vector<int> lens(size, 0);
		for (int i = 0; i < size; ++i) {
			if (!visited[i]) {
				lens[i] = get_len(i, nums, visited, lens);
			}
			max_len = max(lens[i], max_len);
		}

		return max_len;
	}
};