/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    // 算你狠，暴力都不给过的
    public int countNodes(TreeNode root) {
        if (root == null) {
            return 0;
        }
        TreeNode left = root.left, right = root.right;
        int l = 1, r = 1;
        while (left != null) {
            l++;
            left = left.left;
        }
        while (right != null) {
            r++;
            right = right.right;
        }

        if (l == r) {
            return (1 << l) - 1;
        }
        return 1 + countNodes(root.right) + countNodes(root.left);
    }
}