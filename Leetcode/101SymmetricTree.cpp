/*************************************************************************
	> File Name: 101SymmetricTree.cpp
	> Author: Yaning Wang
	> Mail: wangyaning6166@gmail.com
	> Created Time: Thu 29 Jun 2017 19:32:40 CST
 ************************************************************************/

#include<iostream>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;


    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        } else {
            return check(root->left, root->right);
        }
    }

    bool check(TreeNode *a, TreeNode *b) {
        if (a == nullptr && b == nullptr) {
            return true;
        } else if (a != nullptr && b != nullptr) {
            return (a->val == b->val && check(a->left, b->right) && check(a->right, b->left));
        } else {
            return false;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

