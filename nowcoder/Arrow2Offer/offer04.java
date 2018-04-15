/**
 * Definition for binary tree
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    int[] pre, in;


    // 区间遵循前闭后开原则
    private TreeNode constructTree(int preStart, int preEnd, int inStart, int inEnd) {
        if (preStart >= preEnd) {
            return null;
        }

        TreeNode node = new TreeNode(pre[preStart]);
        int inMid;
        for (inMid = inStart; inMid < inEnd; inMid++) {
            if (in[inMid] == pre[preStart]) {
                break;
            }
        }

        node.left = constructTree(preStart + 1, preStart + inMid - inStart + 1, inStart, inMid);
        node.right = constructTree(preStart + inMid - inStart + 1, preEnd, inMid + 1, inEnd);
        return node;
    }

    public TreeNode reConstructBinaryTree(int[] pre, int[] in) {
        this.pre = pre;
        this.in = in;

        return constructTree(0, pre.length, 0, pre.length);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] pre = {1,2,4,5,3,7}, in = {4,2,5,1,3,7};
        sol.reConstructBinaryTree(pre, in);
    }
}