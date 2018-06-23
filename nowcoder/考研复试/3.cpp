#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;
using ll = long long;

bool smaller(char a, char b) {
	if (tolower(a) < tolower(b)) {
		return true;
	}
	return false;
}

int main() {
	string str;
	string alphas;
	while (cin >> str) {
		// 去掉非字母部分
		alphas.clear();
		for (auto &ch : str) {
			if (isalpha(ch)) {
				alphas.push_back(ch);
			}
		}
		// 必须使用冒泡或者插入排序，稳定排序
		stable_sort(alphas.begin(), alphas.end(), smaller);
		int idx = 0;
		// 填入str
		for (auto &ch : str) {
			if (isalpha(ch)) {
				ch = alphas[idx++];
			}
		}

		cout << str << "\n";
	}

	return 0;
}
