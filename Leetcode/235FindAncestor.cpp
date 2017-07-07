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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return findAncestor(root, min(p->val, q->val), max(p->val, q->val)); 
        
    }
    // clearer
    TreeNode*findAncestor(TreeNode*root, int left, int right) {
        if (root->val < left) return findAncestor(root->right, left, right);
        if (root->val == left || root->val == right) return root;
        if (root->val > right) return findAncestor(root->left, left, right);
        return root;
    }

    // faster
    TreeNode*findAncestor(TreeNode*root, int left, int right, int mark) {
        while (true) {
            if (root->val < left) {
                root = root->right;
            } else if (root->val > right) {
                root = root->left;
            } else{
                break;
            }
        }
        return root;
    }
};
