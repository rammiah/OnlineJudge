import java.util.ArrayList;
import java.util.List;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        List<Integer> nums = new ArrayList<>();
        List<TreeNode> nodes_current = new ArrayList<>();
        List<TreeNode> nodes_next = new ArrayList<>();
        if (root == null) return result;
        nodes_current.add(root);
        while (!nodes_current.isEmpty()) {
            nums.clear();
            nodes_next.clear();
            for (TreeNode n : nodes_current) {
                nums.add(n.val);
                if (n.left != null) {
                    nodes_next.add(n.left);
                }
                if (n.right != null) {
                    nodes_next.add(n.right);
                }
            }

            result.add(new ArrayList<>(nums));
            List<TreeNode> temp = nodes_current;
            nodes_current = nodes_next;
            nodes_next = temp;
        }

        return result;
    }
}

