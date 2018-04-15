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
    int biggestDepth = 0;

    int result;

    void findValue(TreeNode node, int depth) {
        if (node != null) {
            if (depth > biggestDepth) {
                biggestDepth = depth;
                result = node.val;
            }
            findValue(node.left, depth + 1);
            findValue(node.right, depth + 1);
        }
    }

    public int findBottomLeftValue(TreeNode root) {
        findValue(root, 1);


        return result;
    }
}