#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if ((n & (n - 1)) == 0 
			&& n != 0 && 
			n != 2147483648) {
			return true;
		}
		return false;
	}
};

int main(void) {
	int i = 2147483648;
	i &= (i - 1);

	cout << i  << endl;
	return 0;
}