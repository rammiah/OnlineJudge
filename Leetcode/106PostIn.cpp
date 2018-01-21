class Solution {
private:
    TreeNode *buildTree(vector<int> &post, vector<int> &in, int post_pos, int start, int end) {
        if (start > end) return nullptr;
        if (start == end) {
            return new TreeNode(post[post_pos]);
        }
        TreeNode *mid = new TreeNode(post[post_pos]);
        // 需要在中序中将其分开
        int left_len = 0;
        for (int i = start; i <= end; ++i) {
            if (post[post_pos] == in[i]) {
                left_len = i - start;
                break;
            }
        }

        mid->left = buildTree(post, in, post_pos - end + start + left_len - 1, start, start + left_len - 1);
        mid->right = buildTree(post, in, post_pos - 1, start + left_len + 1, end);

        return mid;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(postorder, inorder, postorder.size() - 1, 0, postorder.size() - 1);
    }
};

