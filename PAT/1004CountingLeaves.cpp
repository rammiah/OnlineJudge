#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

int maxLevel = 0;

void Input(vector<vector<int>>& tree, const int N) {
	int people = 0;
	int childCount = 0;
	int children = 0;
	vector<int> _tree;
	for (int i = 0; i < N; i++) {
		_tree.clear();
		cin >> people >> childCount;
		for (int j = 0; j < childCount; j++) {
			cin >> children;
			_tree.push_back(children);
		}
		tree[people] = _tree;
	}
}
void Count(const vector<vector<int>>& tree, const int people, const int level, vector<int>& result) {
	bool hasChild = false;
	maxLevel = maxLevel > level ? maxLevel : level;
	for (auto i = 0; i < tree[people].size(); ++i) {
			hasChild = true;
			Count(tree, tree[people][i], level + 1, result);
	}
	if (!hasChild) {
		++result[level];
	}
}

int main(void) {
	int people = 0;
	int lines = 0;
	cin >> people >> lines;
	vector<vector<int>> tree(people + 1, vector<int>());
	Input(tree, lines);
	vector<int> result(people + 1, 0);
	Count(tree, 1, 1, result);
	cout << result[1];
	for (int i = 2; i <= maxLevel; i++) {
		cout << " " << result[i];
	}
	cout << endl;
	return 0;
}
/*
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.
Input
Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, 
and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:
ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a 
sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.
Output
For each test case, you are supposed to count those family members who have no child for every seniority level 
starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.
The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on 
the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.
Sample Input
2 1
01 1 02
Sample Output
0 1
*/