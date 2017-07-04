#include <iostream>
#include <vector>
#include <stack>
#include <string>

using std::string;
using std::vector;
using std::stack;
using std::cout;
using std::cin;
using std::endl;

class Solution {
private:
	bool IsNum(string& str) {
		// 坑，是否为负数，不能只靠符号，还要考虑长度大于1
		if (str[0] >= '0' && str[0] <= '9' || str[0] == '-' && str.length() > 1) {
			return true;
		}
		return false;
	}

	int ToInt(string& str) {
		int res = 0;
	    auto len = str.length();
		for (size_t i = 0; i < len; i++) {
			if (str[i] == '-') {
				continue;
			}
			res = res * 10 + str[i] - '0';
		}
		if (str[0] == '-') {
			return -res;
		}
		return res;
	}

	int Calcu(int left, int right, char opera) {
		switch (opera) {
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			return left / right;
		default:
			return 0;
			break;
		}
	}
public:
	int evalRPN(vector<string>& tokens) {
		stack<int> operand;
		int numA, numB;
		for (auto i = 0u; i < tokens.size(); ++i) {
			if (IsNum(tokens[i])) {
				operand.push(ToInt(tokens[i]));
			}
			else {
				numB = operand.top();
				// 这弹出真难用，就不能返回元素么？还要用top得到栈顶元素，怀念java
				operand.pop();
				numA = operand.top();
				operand.pop();
				operand.push(Calcu(numA, numB, tokens[i][0]));
			}
		}
		return operand.top();
	}
};

int main(void) {
	Solution sol;
	vector<string> str = { "-78","-33","196","+","-19","-","115","+","-","-99","/","-18","8","*","-86","-","-",
		"16","/","26","-14","-","-","47","-","101","-","163","*","143","-","0","-","171","+",
		"120","*","-60","+","156","/","173","/","-24","11","+","21","/","*","44","*","180","70",
		"-40","-","*","86","132","-84","+","*","-","38","/","/","21","28","/","+","83","/","-31",
		"156","-","+","28","/","95","-","120","+","8","*","90","-","-94","*","-73","/","-62","/","93",
		"*","196","-","-59","+","187","-","143","/","-79","-89","+","-" };
	cout << sol.evalRPN(str) << endl;

	return 0;
}