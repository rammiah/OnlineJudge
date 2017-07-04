/*************************************************************************
	> File Name: 104MaxDepth.cpp
	> Author: Yaning Wang
	> Mail: wangyaning6166@gmail.com
	> Created Time: Thu 29 Jun 2017 19:55:08 CST
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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        if (left > right) {
            return left + 1;
        } else {
            return right + 1;
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
