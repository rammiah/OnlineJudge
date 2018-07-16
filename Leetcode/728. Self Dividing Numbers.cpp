class Solution {
	bool is_self_divided(int num) {
		int t = num;

		while (t > 0) {
			if (t % 10 == 0) {
				return false;
			}
			if (num % (t % 10)) {
				return false;
			}
			t /= 10;
		}

		return true;
	}
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> result;
		// 区间左闭右闭
		for (int i = left; i <= right; ++i) {
			if (is_self_divided(i)) {
				result.push_back(i);
			}
		}

		return result;
	}
};
