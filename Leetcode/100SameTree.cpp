/*************************************************************************
	> File Name: 100SameTree.cpp
	> Author: Yaning Wang
	> Mail: wangyaning6166@gmail.com
	> Created Time: Thu 29 Jun 2017 19:25:50 CST
 ************************************************************************/

#include <iostream>


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p != nullptr && q != nullptr) {
            return (p->val == q->val && isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
        } else {
            return false;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
