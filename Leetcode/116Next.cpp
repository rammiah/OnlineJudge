/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr) return;
        queue<TreeLinkNode*> cur_nodes, last_nodes;
        cur_nodes.push_back(root);
        while (!cur_nodes.empty()) {
            cur_nodes.swap(last_nodes);
        }

    }
};
