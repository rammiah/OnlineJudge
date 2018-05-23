/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

set<int> s;

class Solution {
    bool traverse(TreeNode *node, const int &k) {
        if (node != nullptr) {
            if (s.find(node->val) != s.end()) {
                return true;
            }
            s.insert(k - node->val);
            return traverse(node->left, k) || traverse(node->right, k);
        }

        return false;
    }
public:
    bool findTarget(TreeNode* root, int k) {
        // traverse
        s.clear();
        return traverse(root, k);
    }
};