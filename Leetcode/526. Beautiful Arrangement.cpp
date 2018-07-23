class Solution {
	int result = 0;
	int used[16];

	void bt(int idx, int end) {
		if (idx == end + 1) {
			++result;
			return;
		}
		for (int i = 1; i <= end; ++i) {
			if (used[i] == 0 && (i % idx == 0 || idx % i == 0)) {
				used[i] = 1;
				bt(idx + 1, end);
				used[i] = 0;
			}
		}
	}
public:
	int countArrangement(int N) {
		// 使用dp或者bt
		result = 0;
		memset(used, 0, sizeof(used));
		bt(1, N);
		return result;
	}
};
