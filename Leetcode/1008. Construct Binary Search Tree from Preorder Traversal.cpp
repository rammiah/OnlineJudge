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
    // [start, end)
    TreeNode *bstFromPreorder(vector<int> &preorder, const int &start, const int &end) {
        if (start >= end) {
            return nullptr;
        }
        // 在start后查找第一个比preorder[start]大的数
        TreeNode *node = new TreeNode(preorder[start]);
        // cout << node->val << "\n";
        int big;
        for (big = start + 1; big < end; ++big) {
            if (node->val < preorder[big]) {
                break;
            }
        }
        // 递归完成构造
        node->left = bstFromPreorder(preorder, start + 1, big);
        node->right = bstFromPreorder(preorder, big, end);
        return node;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // cout << "hello world\n";
        return bstFromPreorder(preorder, 0, preorder.size());
    }
};
