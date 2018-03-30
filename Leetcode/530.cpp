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
    void in_order(TreeNode* root, vector<int> &values) {
        if (root != nullptr) {
            in_order(root->left, values);
            values.push_back(root->value);
            in_order(root->right, values);
        }
    }
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> values;
        in_order(root, values);
        if (values.size() <= 1) {
            return 0;
        }
        int min_diff = INT_MAX;
        int size = values.size();
        for (int i = 0; i < size - 1; ++i) {
            min_diff = min(min_diff, abs(values[i] - values[i + 1]));
        }

        return min_diff;
    }
};