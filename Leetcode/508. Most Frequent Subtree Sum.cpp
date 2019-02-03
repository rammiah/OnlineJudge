class Solution {
    int travel(TreeNode *node, std::map<int, int> &freq) {
        // 保证不为空
        assert(node != nullptr);
        int sum = node->val;
        if (node->left != nullptr && node->right != nullptr) {
            sum += travel(node->right, freq) + travel(node->left, freq);
        } else if (node->left != nullptr) {
            sum += travel(node->left, freq);
        } else if (node->right != nullptr) {
            sum += travel(node->right, freq);
        }
        ++freq[sum];
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        // 查找所有的子树和并找到频率最大的
        std::vector<int> res = {};
        if (root != nullptr) {
            std::map<int, int> freq;
            travel(root, freq);
            int max_freq = 0;
            // 查找频率最大的
            for (auto &pair : freq) {
                if (pair.second > max_freq) {
                    max_freq = pair.second;
                    res.clear();
                    res.push_back(pair.first);
                } else if (pair.second == max_freq) {
                    // 相等就放到里面
                    res.push_back(pair.first);
                }
            }
        }
        return res;
    }
};

