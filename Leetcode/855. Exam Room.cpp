using namespace std;
using ll = long long;
class ExamRoom {
public:
	set<ll> seats;
	int n;
	ExamRoom(int N) {
		n = N;
	}

	int seat() {
		// 寻找座位
		int result = 0;
		if (seats.size() != 0) {
			// 不是0就找比较大的
			// 在每两个间选择
			if (seats.size() == 1) {
				// 寻找离
				int val = *seats.begin();
				if (val >= n / 2) {
					result = 0;
				}
				else {
					result = n - 1;
				}
			}
			else {
				result = 0;
				int idx = 0;
				int max_len = 0;
				// 查看0是否占用
				if (!seats.count(0)) {
					max_len = *seats.begin() - 0;
					result = 0;
				}
				auto it = seats.begin(), end = seats.end();
				while (it != end) {
					int len = (*it - idx) / 2;
					if (len > max_len) {
						max_len = len;
						result = (*it + idx) / 2;
					}
					idx = *it;
					++it;
				}
				// 看最后一个
				int back = *seats.rbegin();
				idx = n - 1;
				if ((idx - back) / 2 > max_len) {
					max_len = (idx - back) / 2;
					result = (idx + back) / 2;
				}
				if (!seats.count(n - 1)) {
					int len = n - 1 - *seats.rbegin();
					if (len > max_len) {
						max_len = len;
						result = n - 1;
					}
				}
			}
		}

		seats.insert(result);
		return result;
	}

	void leave(int p) {
		seats.erase(seats.find(p));
	}
};
