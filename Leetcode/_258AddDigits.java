package Leetcode;

import java.util.Scanner;

/**
 * Created by yaning on 17-5-23.
 */
public class _258AddDigits {

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        Solution sol = new Solution();

        int i = in.nextInt();

        System.out.println(sol.addDigits(i));

        System.out.println(sol.Best(i));
        in.close();
    }

    static class Solution{
        public int addDigits(int num) {
            int res = 0;
            while (num > 0){
                res += num % 10;
                num /= 10;
            }
            if (res < 10){
                return res;
            }
            else{
                return addDigits(res);
            }
        }

        public int Best(int num){
            return 1 + (num - 1) % 9;
        }
    }

}

