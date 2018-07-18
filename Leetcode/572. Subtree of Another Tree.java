class Solution {
    private boolean equal(TreeNode a, TreeNode b) {
        if (a == null && b == null) {
            return true;
        } else if (a == null || b == null) {
            return false;
        }
        return a.val == b.val && equal(a.left, b.left) && equal(a.right, b.right);
    }


    public boolean isSubtree(TreeNode s, TreeNode t) {
        // 检测t是否是s子树
        if (s == null && t == null) {
            return true;
        } else if (s == null || t == null) {
            return false;
        }
        if (s.val == t.val && equal(s, t)) {
            return true;
        }
        return isSubtree(s.left, t) || isSubtree(s.right, t);
    }
}
