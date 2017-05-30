package Leetcode;

/**
 * Created by yaning on 17-5-29.
 */
public class _396BiggestFunction {

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] arr = { 1,2,3,4,5,6,7,8,9,10 };
        System.out.println(sol.maxRotateFunction(arr));
    }

    static class Solution {
        public int maxRotateFunction(int[] A) {
            if (A.length == 0){
                return 0;
            }
            int len = A.length;
            int sum = 0;
            int temp = 0;

            for (int i = 0; i < len; i++) {
                temp += i * A[i];
                sum += A[i];
            }
            int max = temp;
            for (int i = 1; i < len; i++) {
                temp = temp + sum - len * A[len - i];
                if (temp > max) {
                    max = temp;
                }
            }

            return max;
        }
    }

}
