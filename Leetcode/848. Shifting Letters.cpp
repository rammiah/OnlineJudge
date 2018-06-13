class Solution {
public:
	string shiftingLetters(string S, vector<int>& shifts) {
		string result;
		for (auto &ch : S) {
			ch -= 'a';
		}
		int idx = shifts.size() - 1;
		int sum_shift = 0;
		while (idx >= 0) {
			sum_shift = (sum_shift + shifts[idx] % 26) % 26;
			S[idx] = (S[idx] + sum_shift) % 26 + 'a';
			idx--;
		}

		return S;
	}
};