class Solution {
private:
    // start是数字在pre中的位置,建树
    TreeNode *buildTree(vector<int> &pre, vector<int> &in, int pre_pos, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) {
            return new TreeNode(pre[pre_pos]);
        }
        TreeNode *mid = new TreeNode(pre[pre_pos]);
        // 需要在中序中将其分开
        int left_len = 0;
        for (int i = start; i <= end; ++i) {
            if (pre[pre_pos] == in[i]) {
                left_len = i - start;
                break;
            }
        }

        mid->left = buildTree(pre, in, pre_pos + 1, start, start + left_len - 1);
        mid->right = buildTree(pre, in, pre_pos + left_len + 1, start + left_len + 1, end);

        return mid;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
    }
};

