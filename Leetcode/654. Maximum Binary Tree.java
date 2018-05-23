_654. Maximum Binary Tree.java
class Solution {
    private TreeNode buildTree(int[] nums, int start, int end) {
        if (start >= end) {
            return null;
        }
        // find max value
        int max_idx = start;
        for (int i = start; i < end; i++) {
            max_idx = nums[i] > nums[max_idx] ? i : max_idx;
        }
        // build tree node
        TreeNode node = new TreeNode(nums[max_idx]);
        node.left = buildTree(nums, start, max_idx);
        node.right = buildTree(nums, max_idx + 1, end);
        return node;
    }

    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return buildTree(nums, 0, nums.length);
    }
}