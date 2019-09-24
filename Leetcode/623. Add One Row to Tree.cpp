struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    enum Direction {
        Left, Right
    };

    TreeNode *addOneRow(TreeNode *root, int v, int d, Direction dir) {
        // 递归完成操作
        //assert(d >= 1)
        if (root == nullptr) {
            return d == 1 ? new TreeNode(v) : nullptr;
        }
        if (d == 1) {
            TreeNode *n = new TreeNode(v);
            if (dir == Left) {
                n->left = root;
            } else {
                n->right = root;
            }
            return n;
        }
        root->left = addOneRow(root->left, v, d - 1, Left);
        root->right = addOneRow(root->right, v, d - 1, Right);
        return root;
    }

public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        // 递归完成操作
        return addOneRow(root, v, d, Left);
    }
};
