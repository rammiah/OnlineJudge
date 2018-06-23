#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;



int main() {
	string str;
	while (cin >> str) {
		reverse(str.begin(), str.end());
		cout << str << "\n";
	}

	return 0;
}
