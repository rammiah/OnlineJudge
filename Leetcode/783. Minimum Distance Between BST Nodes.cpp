/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	void update(int &a, int b) {
		a = a < b ? a : b;
	}
	
	void traverse(vector<int> &v, TreeNode *node) {
		if (node != nullptr) {
			traverse(v, node->left);
			v.push_back(node->val);
			traverse(v, node->right);
		}
	}
public:
    int minDiffInBST(TreeNode* root) {
    	vector<int> v;
    	traverse(v, root);
    	int result = INT_MAX;
    	int size = v.size();
    	for (int i = 0; i < size - 1; ++i) {
    		update(result, v[i + 1] - v[i]);
		}
		
		return result;
    }
};
