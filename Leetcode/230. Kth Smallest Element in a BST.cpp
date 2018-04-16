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
    int find(TreeNode *node, vector<int> &vals) {
        if (node != nullptr) {
            find(node->left, vals);
            vals.push_back(node->val);
            find(node->right, vals);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vals;
        find(root, vals);
        return vals[k - 1];
    }
};