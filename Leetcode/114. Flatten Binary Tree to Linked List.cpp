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
    // Similar way in a recursive manner using post-order traversal (from bottom to the up)
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* rightSave = root->right;
        root->right = root->left;
        root->left = nullptr;
        
        // The key part:
        // Since root->left was already flattened previously
        // just go the right most node of root's left tree and point it to the saved right child
        while(root->right) {
            root = root->right;
        }
        root->right = rightSave;
    }
};