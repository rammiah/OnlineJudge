import java.util.Arrays;

class Solution {
    String[] strs;
    int index;
    int len;
    boolean build() {
        if (index >= len) {
            return false;
        } else if (strs[index].equals("#")) {
            return true;
        } else {
            index++;
            if (!build()) {
                return false;
            }
            index++;
            return build();
        }
    }

    public boolean isValidSerialization(String preorder) {
        strs = preorder.split(",");
        System.out.println(Arrays.toString(strs));
        len = strs.length;
        index = 0;
        return build() && index == len - 1;
    }
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.isValidSerialization("9,3,4,#,#,1,#,#,2,#,6,#,#"));
        System.out.println(sol.isValidSerialization("9,#,92,#,#"));
    }
}