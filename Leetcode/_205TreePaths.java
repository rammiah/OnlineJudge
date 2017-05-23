import java.util.ArrayList;
import java.util.List;

/**
 * Created by yaning on 17-5-21.
 */
public class Leet205TreePaths {
    public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
    }

    public class Solution {
        public List<String> binaryTreePaths(TreeNode root) {
            List<String>result = new ArrayList<String>();
            if (root == null){
                ;
            }
            else if (root.left == null && root.right == null){
                result.add(String.valueOf(root.val));
            }
            else{
                Search(root.left, String.valueOf(root.val), result);
                Search(root.right, String.valueOf(root.val), result);
            }
            return result;
        }
        public void Search(TreeNode root, String last, List<String>result){
            if (root == null){
                return;
            }
            else if (root.left == null && root.right == null){
                result.add(last + "->" + root.val);
            }
            else{
                Search(root.left, last + "->" + root.val, result);
                Search(root.right, last + "->" +root.val, result);
            }
        }
    }
}
