#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;
using ll = long long;

// 字符转换为键盘上的数字
int char2btn[] = { 2,2,2, 3,3,3, 4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9 };
// 字符转换为按键次数
int char2time[] = { 1, 2, 3, 1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4 };

int get_time(string &str) {
	int result = 0;
	// 开始按键
	// 先转成数字
	for (auto &ch : str) {
		ch -= 'a';
	}
	// 开始吧
	int len = str.length();
	for (int i = 0; i < len - 1; ++i) {
		if (char2btn[str[i]] == char2btn[str[i + 1]]) {
			result += char2time[str[i]] + 2;
		}
		else {
			result += char2time[str[i]];
		}
	}
	result += char2time[str[len - 1]];

	return result;
}


int main() {
	string str;
	while (cin >> str) {
		cout << get_time(str) << "\n";
	}

	return 0;
}
