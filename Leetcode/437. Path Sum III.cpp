//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
    int dfs(TreeNode *node, int sum, int target) {
        if (node != nullptr) {
            sum += node->val;
            return (sum == target) + dfs(node->left, sum, target) + dfs(node->right, sum, target);
        }

        return 0;
    }

public:
    int pathSum(TreeNode *root, int sum) {
        if (root != nullptr) {
            return dfs(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
        }
        return 0;
    }
};

