/*************************************************************************
	> File Name: 110BST.cpp
	> Author: Yaning Wang
	> Mail: wangyaning6166@gmail.com
	> Created Time: Sat 01 Jul 2017 11:29:11 CST
 ************************************************************************/

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return isBalanced(root->left) && isBalanced(root->right) && abs(depth(root->left) - depth(root->right)) <= 1;
    }

    int depth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return max(depth(root->left), depth(root->right)) + 1;
    }
};
