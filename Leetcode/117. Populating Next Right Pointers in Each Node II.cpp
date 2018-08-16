struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        vector<TreeLinkNode*> cur, next;
        if (root != nullptr) {
            cur.push_back(root);
        }

        while (!cur.empty()) {
            TreeLinkNode *t = nullptr;
            for (int i = cur.size() - 1; i >= 0; --i) {
                cur[i]->next = t;
                t = cur[i];
                if (t->right != nullptr) {
                    next.push_back(t->right);
                }
                if (t->left != nullptr) {
                    next.push_back(t->left);
                }
            }
            next.swap(cur);
            next.clear();
            reverse(cur.begin(), cur.end());
        }
    }
};