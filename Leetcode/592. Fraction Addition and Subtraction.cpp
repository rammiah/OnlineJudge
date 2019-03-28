class Solution {
	int gcd(int a, int b) {
		a = abs(a);
		b = abs(b);
		if (a == 0 || b == 0) {
			return a == 0 ? b : a;
		}
		while (b != 0) {
			int t = b;
			b = a % b;
			a = t;
			// a, b = b, a % b
		}
		return a;
	}

public:
	string fractionAddition(string expression) {
		int up = 0, down = 1;
		std::stringstream ss(expression);
		int a, b;
		char ch;
		while (ss >> a >> ch >> b) {
			int t = gcd(b, down);
			up *= b / t;
			a *= down / t;
			up += a;
			down = b * down / t;
			t = gcd(down, up);
			down /= t;
			up /= t;
		}
		if (up == 0) {
			return "0/1";
		}
		return std::to_string(up) + "/" + std::to_string(down);
	}
};
