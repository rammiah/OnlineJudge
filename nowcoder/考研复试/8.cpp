#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int main() {

	int a, b, c;
	int x, y, z;
	double radius;
	double pi = acos(-1);
	while (cin >> a >> b >> c >> x >> y >> z) {
		radius = sqrt(pow(a - x, 2)+  pow(b - y, 2)+ pow(c - z, 2));
		cout << fixed << setprecision(3) << radius << " " << 4 / 3.0 * pi * pow(radius, 3) << "\n";
	}

	return 0;
}
