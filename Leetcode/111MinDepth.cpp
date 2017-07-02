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
    int minDepth(TreeNode*root, int depth) {
        if (root == nullptr) {
            return 1024000; // 开始写的1024居然不够大/(ㄒoㄒ)/~~情怀都不让有吗？
        } else if (root->left == nullptr && root->right == nullptr){
            return depth + 1;
        } else{
            return min<int>(minDepth(root->left, depth), minDepth(root->right, depth)) + 1;
        }
    }

public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        } else if (root->left == nullptr && root->right == nullptr){
            return 1;
        } else {
            return min<int>(minDepth(root->left, 1), minDepth(root->right, 1));
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}


