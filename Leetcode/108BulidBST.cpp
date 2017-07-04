/*************************************************************************
	> File Name: 108BulidBST.cpp
	> Author: Yaning Wang
	> Mail: wangyaning6166@gmail.com
	> Created Time: Fri 30 Jun 2017 13:30:06 CST
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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return buildTree(nums, 0, (int) (nums.size() - 1));
    }

    TreeNode *buildTree(const vector<int> &nums, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, start, mid - 1);
        root->right = buildTree(nums, mid + 1, end);
        return root;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

