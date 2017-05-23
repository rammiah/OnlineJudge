#include <iostream>
#include <vector>
using std::vector;
using std::endl;
using std::cout;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
	vector<vector<int>>	fina;
	void Search(vector<int>& res, TreeNode* search, int sum, int target) {
		if (search == nullptr) {
			return;
		}
		if (search->val + sum == target && search->left == nullptr && search->right == nullptr) {
			res.push_back(search->val);
			fina.push_back(res);
			res.pop_back();
			return;
		}
		else {
			res.push_back(search->val);
			Search(res, search->left, sum + search->val, target);
			Search(res, search->right, sum + search->val, target);
			res.pop_back();
			return;
		}
	}
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		if (root == nullptr) {
			return fina;
		}
		vector<int> res(1, root->val);
		if (root->val == sum && root->left == nullptr && root->right == nullptr) {
			fina.push_back(res);
		}
		Search(res, root->left, root->val, sum);
		Search(res, root->right, root->val, sum);
		return fina;
	}
};

int main(void) {

	return 0;
}