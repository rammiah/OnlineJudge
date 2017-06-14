/*************************************************************************
	> File Name: _013RomanToInt.java
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年06月14日 星期三 22时27分08秒
 ************************************************************************/

package Leetcode;

/**
 * Time: 17-6-14 下午10:01
 * Created by yaning on 17-6-14.
 * Email: wangyaning6166@gmail.com
 * School: HUST
 */
public class _013RomanToInt {
    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.romanToInt("IV"));
    }

    static class Solution {
        int romanToInt(String s) {
            int[] nums = new int[26];
            nums['I' - 'A'] = 1;
            nums['V' - 'A'] = 5;
            nums['X' - 'A'] = 10;
            nums['L' - 'A'] = 50;
            nums['C' - 'A'] = 100;
            nums['D' - 'A'] = 500;
            nums['M' - 'A'] = 1000;
            int sol = 0;
            int count = s.length();
            s += s.charAt(count - 1);
            // 4,40,400都是只会一个左大于右
            for (int i = 0; i < count; i++) {
                if (nums[s.charAt(i) - 'A'] >= nums[s.charAt(i+1) - 'A']) {
                    sol += nums[s.charAt(i) - 'A'];
                } else {
                    sol -= nums[s.charAt(i) - 'A'];
                }
            }
            return sol;
        }
    }
}

