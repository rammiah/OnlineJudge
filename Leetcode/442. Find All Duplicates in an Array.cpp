int cnts[1000000];

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		memset(cnts, 0, sizeof(cnts));
		vector<int> result;
		for (auto &num : nums) {
			if (cnts[num]) {
				result.push_back(num);
			}
			else {
				cnts[num]++;
			}
		}
		return result;
	}
};
