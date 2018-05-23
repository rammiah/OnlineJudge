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
public:
    /// 永远不要觉得你的魔改可以超过编译器
    vector<double> averageOfLevels(TreeNode* root) {
        vector<TreeNode*> first, second;
        if (root != nullptr) {
            first.push_back(root);
        }
        vector<double> result;
        while (!first.empty()) {
            double sum = 0;
            for (auto &node : first) {
                sum += node->val;
                if (node->left != nullptr) {
                    second.push_back(node->left);
                }
                if (node->right != nullptr) {
                    second.push_back(node->right);                    
                }
            }
            result.push_back(sum / first.size());
            first.clear();
            swap(first, second);
        }

        return result;
    }
};