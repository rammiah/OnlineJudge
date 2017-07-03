package Leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by yaning on 17-5-27.
 */
public class _144PreTree {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public static void main(String[] args){
        Solution sol = new Solution();
        System.out.println("Hello world.");
    }

    static class Solution {
        public List<Integer> preorderTraversal(TreeNode root) {
            List<Integer>list = new ArrayList<Integer>();
            preSearch(root, list);
            return list;
        }

        void preSearch(TreeNode root, List<Integer> list){
            if (root == null) {
                return;
            }
            list.add(root.val);
            preSearch(root.left, list);
            preSearch(root.right, list);
        }
    }
}
