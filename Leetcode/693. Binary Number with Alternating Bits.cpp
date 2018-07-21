class Solution {
public:
	bool hasAlternatingBits(int n) {
		// 使用异或
		int t = n;
		while (t > 0) {
			if (((t >> 1) ^ t) & 1) {
				t >>= 1;
				continue;
			} 
			return false;
		}
		return true;
	}
};