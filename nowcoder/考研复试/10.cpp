#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

struct Node {
	char ch;
	Node *left, *right;
	Node(char ch) : ch(ch) {}
};

Node *build(string &str, int &idx) {
	if (str[idx] == '#') {
		idx++;
		return nullptr;
	}
	Node *node = new Node(str[idx++]);
	node->left = build(str, idx);
	node->right = build(str, idx);
	return node;
}

void in_order(Node *node) {
	if (node != nullptr) {
		in_order(node->left);
		cout << node->ch << " ";
		in_order(node->right);
	}
}

int main() {
	string str;
	cin >> str;
	int idx = 0;
	Node *tree = build(str, idx);
	// 中序遍历
	in_order(tree);
	return 0;
}