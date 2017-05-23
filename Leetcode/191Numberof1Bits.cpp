#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int i = 0;
		while (n > 0) {
			if (n % 2 == 1) {
				++i;
			}
			n /= 2;
		}
		return i;
	}
};

int main(void) {
	Solution sol;
	cout << sol.hammingWeight(11) << endl;
	return 0;
}