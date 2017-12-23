import java.util.ArrayList;
import java.util.List;

/**
 * Definition for a binary tree node.
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();

        if (root == null) {
            return result;
        }
        List<TreeNode> temp = new ArrayList<>();
        temp.add(root);
        List<TreeNode> next = new ArrayList<>();
        List<Integer> values = new ArrayList<>();
        boolean reverse = false;
        while (!temp.isEmpty()) {
            TreeNode node;
            if (reverse) {

                for (int i = temp.size() - 1; i >= 0; i--) {
                    values.add(temp.get(i).val);
                }
                reverse = false;
            } else {
                for (TreeNode node1 : temp) {
                    values.add(node1.val);
                }
                reverse = true;
            }

            for (TreeNode node1 : temp) {
                node = node1;
                if (node.left != null) {
                    next.add(node.left);
                }
                if (node.right != null) {
                    next.add(node.right);
                }
            }

            List<TreeNode> t = temp;
            temp = next;
            next = t;
            next.clear();
            result.add(new ArrayList<>(values));
            values.clear();
        }

        return result;
    }
}