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
private:
    void getSum(TreeNode* root, int &sum, int num) {
        if (root == nullptr) return;
        if (root->left == nullptr && root->right == nullptr) sum += num * 10 + root->val;
        else {
            getSum(root->left, sum, num * 10 + root->val);
            getSum(root->right, sum, num * 10 + root->val);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        if (root != nullptr){
           getSum(root, sum, 0);      
        }

        return sum;
    }
};
