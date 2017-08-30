
//Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    int sum = 0;
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) return 0;
        return getSum(root, false);
//        return 0;
    }

    private int getSum(TreeNode root, boolean isLeft) {
        if (root == null) return 0;
        if (isLeft && root.left == null && root.right == null) {
            return root.val;
        }
        else {
            return getSum(root.left, true) + getSum(root.right, false);
        }
    }
}

