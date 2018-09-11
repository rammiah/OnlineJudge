class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root != nullptr) {
            if (root->val == key) {
                // 删除这个
                // 分4种情况
                if (root->left == nullptr && root->right == nullptr) {
                    return nullptr;
                }
                // 右侧为空(包含了左侧为空都是返回nullptr)
                else if (root->right == nullptr) {
                    return root->left;
                }
                // 左侧为空
                else if (root->left == nullptr) {
                    return root->right;
                }
                // 都不为空
                else {
                    // 右侧最左边的那个
                    TreeNode *right = root->right;
                    TreeNode *pri = nullptr;
                    while (right->left != nullptr) {
                        pri = right;
                        right = right->left;
                    }
                    if (right == root->right) {
                        right->left = root->left;
                        return right;
                    }
                    pri->left = right->right;
                    root->val = right->val;
                    return root;
                }
            }
            else if (root->val > key) {
                root->left = deleteNode(root->left, key);
            }
            else {
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};