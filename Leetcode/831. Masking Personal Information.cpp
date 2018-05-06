class Solution {
	void to_lower(string &s) {
		int len = s.length();
		for (auto &ch : s) {
			if (ch >= 'A' && ch <= 'Z') {
				ch += 0x20;
			}
		}
	}
	string clean(string &s) {
		string res;
		for (auto &ch : s) {
			if (ch >= '0' && ch <= '9') {
				res.push_back(ch);
			}
		}
		return res;
	}
public:
    string maskPII(string S) {
		string result;
		// email address
		if (S.find('@') != -1) {
			to_lower(S);
			
			result.append(S.substr(0, 1));
			result.append("*****");
			int at = S.find('@');
			result.append(S.substr(at - 1, 1));
			result.append(S.substr(at));
			return result;
		} else {
			string cleaned = clean(S);
			char str[20];
			int len = cleaned.length();
			if (len == 10) {
				// local number
				result.append("***-***-");
				result.append(cleaned.substr(6));
			} else {
				// world number 
				result.append("+");
				for (int i = 0; i < len - 10; ++i) {
					result.append("*");
				}
				result.append("-***-***-");
				result.append(cleaned.substr(len - 4));
			}
		}
		return result;
    }
};

