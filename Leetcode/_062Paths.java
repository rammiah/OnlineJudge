public class Solution {
    // 有必要再优化一下
    public static long sum(int m, int n) {
        int[] first = new int[n], second = new int[n];
        for (int i = 0; i < n; i++) {
            first[i] = 1;
        }
        int[] temp = null;
        for (int i = 1; i < m; i++) {
            second[0] = 1;
            for (int j = 1; j < n; j++) {
                second[j] = second[j - 1] + first[j];
            }
            temp = first;
            first = second;
            second = temp;
        }

        return first[n - 1];
    }

    public static void main(String[] args) {
        System.out.println(sum(2, 2));
    }
}

