class Solution {
public:
	bool checkRecord(std::string s) {
		int a_cnt = 0, l_cnt = 0;
		char last = ' ';
		for (auto& c : s) {
			if (c == 'A') {
				++a_cnt;
			}
			else if (c == 'L') {
				if (last == 'L') {
					++l_cnt;
				}
				else {
					l_cnt = 1;
				}
			}
			last = c;
			if (a_cnt >= 2 || l_cnt >= 3) {
				return false;
			}
		}
		return true;
	}
};
