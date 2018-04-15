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
    void buildNode(TreeNode node, StringBuilder sb) {
        if (node == null) {
            return;
        } else if (node.left == null && node.right == null) {
            sb.append(node.val);
        } else if (node.left == null) {
            sb.append(node.val).append("()(");
            buildNode(node.right, sb);
            sb.append(")");
        } else if (node.right == null) {
            sb.append(node.val).append("(");
            buildNode(node.left, sb);
            sb.append(")");
        } else {
            sb.append(node.val).append("(");
            buildNode(node.left, sb);
            sb.append(")(");
            buildNode(node.right, sb);
            sb.append(")");
        }
    }

    public String tree2str(TreeNode t) {
        StringBuilder sb = new StringBuilder();
        buildNode(t, sb);
        return sb.toString();
    }
}