void up_min(int &a, int b) {
	a = a > b ? b : a;
}

void up_max(int &a, int b) {
	a = a > b ? a : b;
}
class Solution {
public:
	int findLHS(vector<int>& nums) {
		if (nums.size() <= 1) {
			return 0;
		}
		map<int, int> m;
		for (auto &num : nums) {
			++m[num];
		}
		int result = 0;
		auto next = m.begin(), end = m.end();
		auto it = next++;
		while (next != end) {
			if (next->first == it->first + 1) {
				up_max(result, next->second + it->second);
			}
			next++;
			it++;
		}
		return result;
	}
};