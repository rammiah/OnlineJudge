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
    int max_length = 0;
    // 遍历一波即可
    int traverse(TreeNode *root) {
        if (root != nullptr) {
            int left = traverse(root->left);
            int right = traverse(root->right);
            max_length = max(max_length, left + right);
            return max(left, right) + 1;
        }

        return 0;
    }
public:
    int diameterOfBinaryTree(TreeNode *root) {
        traverse(root);
        return max_length;
    }
};