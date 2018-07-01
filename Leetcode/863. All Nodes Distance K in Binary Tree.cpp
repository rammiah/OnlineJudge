
vector<int> result;
int node_depth = 0;
// 遍历的
void traverse(TreeNode *node, int depth, int target_depth) {
    if (node != nullptr) {
        if (depth == target_depth) {
            result.push_back(node->val);
            return;
        }
        traverse(node->left, depth + 1, target_depth);
        traverse(node->right, depth + 1, target_depth);
    }
}

bool find_node(TreeNode *root, TreeNode *node, int depth) {
    // 寻找节点的，没啥意思
    if (root != nullptr) {
        if (root == node) {
            node_depth = depth;
            return true;
        }
        return find_node(root->left, node, depth + 1) || find_node(root->right, node, depth + 1);
    }
    return false;
}

void dis(TreeNode *node, TreeNode *target, int k) {
    if (node == target) {
        return;
    }
    else {
        if (find_node(node->left, target, 1)) {
            // 结点在左侧
            if (k == node_depth) {
                result.push_back(node->val);
                dis(node->left, target, k);
            }
            else if (k > node_depth) {
                traverse(node->right, 1, k - node_depth);
                dis(node->left, target, k);
            }
            else {
                dis(node->left, target, k);
            } 
        }
        else if (find_node(node->right, target, 1)) {
            // 结点在右侧
            if (k == node_depth) {
                result.push_back(node->val);
                dis(node->right, target, k);
            }
            else if (k > node_depth) {
                traverse(node->left, 1, k - node_depth);
                dis(node->right, target, k);
            }
            else {
                dis(node->right, target, k);
            }
        }
    }
}

class Solution {
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        
        if (root == nullptr || target == nullptr) {
            return result;
        }
        result.clear();
        // 首先看一下是不是根节点
        if (root == target) {
            // 比较的是结点不是结点的值
            traverse(root, 0, K);
            return result;
        }
        else {
            // 计算结点下面的结点
            traverse(target, 0, K);
            // 找上面的结点
            dis(root, target, K);
        }
        return result;
    }
};
