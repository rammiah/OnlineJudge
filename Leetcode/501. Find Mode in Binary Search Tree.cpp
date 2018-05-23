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
    int last, freq, max_freq;
    void traverse(TreeNode *node, vector<int> &result) {
        if (node != nullptr) {
            traverse(node->left, result);
            if (node->val == last) {
                ++freq;
            } else {
                last = node->val;
                freq = 1;
            }
            if (freq > max_freq) {
                result.clear();
                result.push_back(last);
                max_freq = freq;
            } else if (freq == max_freq) {
                result.push_back(last);
            }
            traverse(node->right, result);
        }
    }
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if (root != nullptr) {
            TreeNode *node = root;
            while (node->left != nullptr) {
                node = node->left;
            }
            last = node->val;
            freq = 0;
            max_freq = 0;
            traverse(root, result);
        }
        return result;
    }
};