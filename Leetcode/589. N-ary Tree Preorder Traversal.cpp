/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
    void pre(vector<int> &nums, Node *root) {
        if (root != nullptr) {
            nums.push_back(root->val);
            for (auto child : root->children) {
                pre(nums, child);
            }
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> res;
        pre(res, root);
        return res;
    }
};
