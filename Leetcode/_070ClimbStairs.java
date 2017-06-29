package Leetcode;

/**
 * Time: 29/06/17 07:58
 * Created by yaning.
 * School: HUST
 * Email: wangyaning6166@gmail.com
 */
public class _070ClimbStairs {
    public static void main(String[] args){
        _070ClimbStairs sol = new _070ClimbStairs();
        System.out.println(sol.climbStairs(4));
    }

    // 分析题目即可
    public int climbStairs(int n) {
        int[] ways = new int[n + 1];
        ways[0] = ways[1] = 1;
        for (int i = 2; i <= n; i++) {
            ways[i] = ways[i - 1] + ways[i - 2];
        }
        return ways[n];
    }
}
