import java.util.ArrayList;
import java.util.List;

class Solution {
    // 早就蒙圈了，拼出来的答案
    // 深度搜索，不多说了
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        if (n == 0) return result;
        int[] queens = new int[n];
        search(0, queens, n, result);
        return result;
    }

    private boolean check(int count, int[] queens) {
        int row_diff = 0;
        int col_diff = 0;
        // 只有1层的时候好像是对的
        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                row_diff = j - i;
                col_diff = queens[j] - queens[i];
                if (row_diff == 0 || col_diff == 0 || row_diff == col_diff || row_diff == -col_diff) {
                    return false;
                }
            }
        }
        return true;
    }

    // 加入到结果中
    private void add(int[] queens, List<List<String>> result) {
        char[] arr = new char[queens.length];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = '.';
        }
        List<String> temp = new ArrayList<>();
        for (int i = 0; i < queens.length; i++) {
            arr[queens[i]] = 'Q';
            temp.add(String.valueOf(arr));
            arr[queens[i]] = '.';
        }
        result.add(temp);
    }

    private void search(int depth, int[] temp, int n, List<List<String>> result) {
        if (depth == n){
            add(temp, result);
            return;
        }
        for (int i = 0; i < n; i++) {
            temp[depth] = i;
            // 放在这可以，
            if (check(depth + 1,temp)) {
                search(depth + 1, temp, n, result);
            }
        }
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.solveNQueens(8));
    }
}
