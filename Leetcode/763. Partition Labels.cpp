class Solution {
	int left_chars[26], right_chars[26];
	// 将s划分为2部分，左侧尽量小，左右没有相同字符
	bool has_same() {
		for (int i = 0; i < 26; ++i) {
			if (left_chars[i] && right_chars[i]) {
				return true;
			}
		}
		return false;
	}
	int partion(string s) {
		// 如何快速计算两者是否有相同字符：int数组吧
		memset(left_chars, 0, sizeof(left_chars));
		memset(right_chars, 0, sizeof(right_chars));
		//开始左侧只有1个字符
		left_chars[s[0] - 'a'] ++;
		for (int i = 1; i < s.length(); ++i) {
			right_chars[s[i] - 'a'] ++;
		}
		// 开始进行右移
		int result = 1;
		while (has_same()) {
			left_chars[s[result] - 'a']++;
			right_chars[s[result] - 'a']--;
			result++;
		}
		return result;
	}

public:
	vector<int> partitionLabels(string s) {
		// 第一个字母获得的范围尽量小
		// 然后直接就是一个子问题
		vector<int> result;
		int t = partion(s);
		result.push_back(t);
		while (t < s.length()) {
			s = s.substr(t);
      // 再次划分
			t = partion(s);
			result.push_back(t);
		}
		return result;
	}
};
