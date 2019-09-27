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
    vector<int> postorder(Node *root) {
        std::vector<int> res;
        // 其实stack更好一点，但是都差不多啦
        std::vector<Node *> nodes;
        if (root != nullptr) {
            nodes.push_back(root);
        }
        while (!nodes.empty()) {
            // 有点麻烦
            // 值读出来，放到最后面
            Node *n = nodes.back();
            res.push_back(n->val);
            nodes.pop_back();
            for (auto child : n->children) {
                nodes.push_back(child);
            }
        }
        // 要是不用reverse就好了
        std::reverse(res.begin(), res.end());
        return res;
    }
};
