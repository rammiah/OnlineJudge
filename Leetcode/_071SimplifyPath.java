import java.util.Stack;

class Solution {
    public String simplifyPath(String path) {
        String[] strs = path.split("/");
        Stack<String> result = new Stack<>();
        for (String str : strs) {
            if (str.equals(".") || str.equals("")) {
                continue;
            }else if (str.equals("..")) {
                if (!result.isEmpty()) {
                    result.pop();
                }
            }else {
                result.push(str);
            }
        }
        StringBuilder sb = new StringBuilder();
        for (String str : result) {
            sb.append("/").append(str);
        }
        if (sb.toString().isEmpty()) return "/";
        return sb.toString();
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
//        System.out.println(sol.isNumber("12e3e10"));
        System.out.println(sol.simplifyPath("/.."));
        // /.. => /
        // /../ => /
        // /... => /...
    }
}
