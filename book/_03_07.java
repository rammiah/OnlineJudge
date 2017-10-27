package book;

import java.util.Scanner;

/*
*
* test case:
* 20 1 8 4 13 6 10 15 2 17 3 19 7 16 8 11 14 9 12 5
* */

public class _03_07 {
    public static void main(String[] args) {
        String str;
        Scanner in = new Scanner(System.in);
        int caseCount = 1;
        while (in.hasNextLine()) {
            int maxSum, minSum;
            int maxIndex = 0, minIndex = 0;
            int tempSum = 0;
            str = in.nextLine();
            String[] strs = str.split(" ");
            int[] nums = new int[strs.length];
            for (int i = 0; i < nums.length; i++) {
                nums[i] = Integer.valueOf(strs[i]);
            }

            if (nums.length < 3) {
                System.out.println("Case " + caseCount++ + ":");
                System.out.println("No maximal and minimal!");
            } else {
                maxSum = minSum = tempSum = nums[0] + nums[1] + nums[2];
                maxIndex = minIndex = 1;
                for (int i = 3; i < nums.length; i++) {
                    tempSum += nums[i] - nums[i - 3];
                    if (tempSum > maxSum) {
                        maxIndex = i - 1;
                        maxSum = tempSum;
                    }
                    if (tempSum < minSum) {
                        minIndex = i - 1;
                        minSum = tempSum;
                    }
                }
                System.out.println("Case " + caseCount++ + ":");
                System.out.printf("Maximum = %d, Minimum = %d, MaxIndex = %d, MinIndex = %d\n",
                        maxSum, minSum, maxIndex, minIndex);
            }
        }

        in.close();
    }
}
