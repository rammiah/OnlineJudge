/*************************************************************************
	> File Name: 107TreeOrderTraversal.cpp
	> Author: Yaning Wang
	> Mail: wangyaning6166@gmail.com
	> Created Time: Thu 29 Jun 2017 20:29:19 CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;


    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    vector<vector<int>>sol;
    void getLevel(vector<TreeNode*>nodes) {
        if (nodes.size() == 0) {
            return;
        }
        vector<int>t;
        vector<TreeNode*>childNodes;
        for (int i = 0; i < nodes.size(); ++i) {
            t.push_back(nodes[i]->val);
            if (nodes[i]->left != nullptr) {
                childNodes.push_back(nodes[i]->left);
            }
            if (nodes[i]->right != nullptr) {
                childNodes.push_back(nodes[i]->right);
            }
        }
        getLevel(childNodes);
        sol.push_back(t);
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return sol;
        }

        sol.push_back(vector<int>(1,root->val));
        vector<TreeNode*>nodes;
        if (root->left != nullptr) {
            nodes.push_back(root->left);
        }
        if (root->right  != nullptr) {
            nodes.push_back(root->right);
        }
        return sol;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
