class Solution {
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> nums;
		int a, b;
		for (const auto &token : tokens) {
			if (token.length() > 1 || token[0] >= '0' && token[0] <= '9') {
				nums.push(stoi(token));
			} else {
				a = nums.top();
				nums.pop();
				b = nums.top();
				nums.pop();
				if (token[0] == '+') {
					nums.push(a + b);
				} else if (token[0] == '-') {
					nums.push(b - a);
				} else if (token[0] == '*') {
					nums.push(a * b);
				} else {
					nums.push(b / a);
				}
			}
		}
		return nums.top();
	}
};
