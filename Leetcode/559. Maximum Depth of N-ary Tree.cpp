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
public:
    int maxDepth(Node* root) {
        if (root != nullptr) {
            int max_depth = 0;
            for (auto &n : root->children) {
                max_depth = max(max_depth, maxDepth(n));
            }
            return max_depth + 1;
        }
        return 0;
    }
};
