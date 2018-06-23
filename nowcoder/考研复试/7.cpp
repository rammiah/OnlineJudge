#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;
using ll = long long;

struct Stu {
	int id;
	int score;
	friend bool operator<(const Stu &a, const Stu &b) {
		if (a.score < b.score) {
			return true;
		}
		else if (a.score == b.score) {
			return a.id < b.id;
		}
		return false;
	}
};


int main() {
	Stu stu;
	vector<Stu> stus;
	int cnt;
	while (cin >> cnt) {
		stus.clear();
		for (int i = 0; i < cnt; ++i) {
			cin >> stu.id >> stu.score;
			stus.push_back(stu);
		}
		sort(stus.begin(), stus.end());
		// 输出
		for (auto &s : stus) {
			cout << s.id << " " << s.score << "\n";
		}
	}

	return 0;
}
