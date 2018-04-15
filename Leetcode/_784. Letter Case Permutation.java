import java.util.ArrayList;
import java.util.List;

class Solution {
    private void dfs(char[] chs, List<String> result, int index) {
        if (index == chs.length) {
            // 递归终止条件
            result.add(new String(chs));
            return;
        }
        if (Character.isAlphabetic(chs[index])) {
            if (Character.isLowerCase(chs[index])) {
                dfs(chs, result, index + 1);
                chs[index] = Character.toUpperCase(chs[index]);
                dfs(chs, result, index + 1);
                chs[index] = Character.toLowerCase(chs[index]);
            } else {
                dfs(chs, result, index + 1);
                chs[index] = Character.toLowerCase(chs[index]);
                dfs(chs, result, index + 1);
                chs[index] = Character.toUpperCase(chs[index]);
            }
        } else {
            dfs(chs, result, index + 1);
        }
    }

    public List<String> letterCasePermutation(String S) {
        ArrayList<String> result = new ArrayList<>();
        char[] chs = S.toCharArray();
        dfs(chs, result, 0);

        return result;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.letterCasePermutation("a1b1"));
    }
}