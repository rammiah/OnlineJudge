struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    // 二叉树节点删除,不需要delete
    void del(TreeNode *&node) {
        if (node->left == nullptr && node->right == nullptr) {
            node = nullptr;
        } else if (node->left == nullptr) {
            TreeNode *right = node->right;
            node = right;
        } else if (node->right == nullptr) {
            TreeNode *left = node->left;
            node = left;
        } else {
            TreeNode *left = node->left;
            if (left->right == nullptr) {
                node = left;
            } else {
                TreeNode *pri = left, *right = pri->right;
                while (right->right != nullptr) {
                    pri = right;
                    right = right->right;
                }
                assert(right != nullptr);
                pri->right = right->left;
                right->left = node->left;
                right->right = node->right;
                node = right;
            }
        }
    }

    void traverse(TreeNode *&node, const int L, const int R) {
        if (node != nullptr) {
            traverse(node->left, L, R);
            traverse(node->right, L, R);
            if (node->val < L || node->val > R) {
                del(node);
            }
        }
    }

public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        TreeNode *node = root;
        traverse(node, L, R);

        return node;
    }
};