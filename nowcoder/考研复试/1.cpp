#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Stu {
	string name;
	int idx;
	int score;
	friend bool operator<(const Stu &a, const Stu &b) {
		if (a.score < b.score) {
			return true;
		}
		else if (a.score == b.score) {
			return a.idx < b.idx;
		}
		return false;
	}

};

int main() {
	int cnt;
	int mode;
	Stu s;
	while (cin >> cnt >> mode) {
		mode = mode == 0 ? -1 : 1;
		vector<Stu> stus;
		for (int i = 0; i < cnt; ++i) {
			cin >> s.name >> s.score;
			s.score *= mode;
			s.idx = i;
			stus.push_back(s);
		}
		sort(stus.begin(), stus.end());

		for (int i = 0; i < cnt; ++i) {
			cout << stus[i].name << " " << stus[i].score * mode << "\n";
		}
	}

	return 0;
}
