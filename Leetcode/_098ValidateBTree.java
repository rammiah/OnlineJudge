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
    void travel(TreeNode node, List<Integer> list) {
        if (node == null) {
            return;
        }
        travel(node.left, list);
        list.add(node.val);
        travel(node.right, list);
    }
    // 直接将树中序遍历，得到的列表一定是递增的
    public boolean isValidBST(TreeNode root) {
        if (root == null) {
            return true;
        }
        ArrayList<Integer> list = new ArrayList<>();
        travel(root, list);
        // 判断是否递增
        for (int i = 0; i < list.size() - 1; i++) {
            if (list.get(i) >= list.get(i + 1)) {
                return false;
            }
        }
        return true;
    }
}
