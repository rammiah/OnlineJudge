class Solution {
public:
	bool checkPerfectNumber(int num) {
		if (num <= 0) {
			return false;
		}
		int sum = 1;
		int sqroot = sqrt(num);
		for (int i = 2; i <= sqroot; ++i) {
			if (num % i == 0) {
				sum += i + num / i;
			}
		}
		// 可开方情况
		if (sqroot * sqroot == num) {
			sum -= sqroot;
		}
		return sum == num;
	}
};
