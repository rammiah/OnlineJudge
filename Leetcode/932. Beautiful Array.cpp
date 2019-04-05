class Solution {
public:
	std::vector<int> beautifulArray(int N) {
        // 写的也太好了吧，不服不行
        /* https://leetcode.com/problems/beautiful-array/discuss/186679/C%2B%2BJavaPython-Odd-%2B-Even-Pattern-O(N) */
		std::vector<int> res{1};
		while (res.size() < N) {
			std::vector<int> tmp;
			for (auto i : res) {
				if (i * 2 - 1 <= N) {
					tmp.push_back(i * 2 - 1);
				}
			}
			for (auto i : res) {
				if (i * 2 <= N) {
					tmp.push_back(i * 2);
				}
			}
			res = std::move(tmp);
		}

		return res;
	}
};