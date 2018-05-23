import java.util.ArrayList;
import java.util.List;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

// 515 largest value in every row
class Solution {
    public List<Integer> largestValues(TreeNode root) {
        // a array to store result
        List<Integer> result = new ArrayList<>();
        // check the null pointer
        if (root == null) {
            return result;
        }
        // a treenode array to store the current row value
        List<TreeNode> oneFloor = new ArrayList<>();
        // add the root node
        oneFloor.add(root);
        // a array to store the next raw of node
        List<TreeNode> newFloor = new ArrayList<>();
        // a temp array used to swap up two array
        List<TreeNode> temp;
        // the max value of each row
        int max = 0; // I just want to set it to zero...
        while (!oneFloor.isEmpty()) {
            // set the value to min_int
            max = Integer.MIN_VALUE;
            // travel current row node
            for (TreeNode node : oneFloor) {
                // check if their left and right pointer
                if (node.left != null) {
                    newFloor.add(node.left);
                }
                if (node.right != null) {
                    newFloor.add(node.right);
                }
                // update the max value
                max = max < node.val ? node.val : max;
            }
            // add the max value
            result.add(max);
            // swap the row
            temp = oneFloor;
            oneFloor = newFloor;
            newFloor = temp;
            // clear the old row
            newFloor.clear();
        }
        // return the result
        return result;
    }
}