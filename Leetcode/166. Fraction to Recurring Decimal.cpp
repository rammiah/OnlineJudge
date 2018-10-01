#include <string>
#include <map>

using namespace std;

class Solution {
public:
    // 搞这么多边界情况，我也是醉了
	string fractionToDecimal(int nume, int denom) {
		long long num = nume, den = denom;
		string res;
		if (num * den < 0) {
			res.append("-");
		}
		num = abs(num);
		den = abs(den);

		if (num >= den) {
			res.append(to_string(num / den));
			num %= den;
		}
		else {
			res.push_back('0');
		}
		// 普遍情况
		map<int, int> reminders;
		string decimal;
		int idx = 0;
		if (num != 0) {
			res.push_back('.');
			bool circle = false;
			while (num != 0) {
				if (reminders.count(num)) {
					circle = true;
					break;
				}
				else {
					reminders[num] = idx;
					decimal.push_back(num * 10 / den + '0');
					num = num * 10 % den;
				}
				idx++;
			}
			if (circle) {
				res.append(decimal.substr(0, reminders[num]) + "(" + decimal.substr(reminders[num]) + ")");
			}
			else {
				res.append(decimal);
			}
		}
		return res;
	}
};
