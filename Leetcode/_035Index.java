package Leetcode;

/**
 * Time: 28/06/17 20:47
 * Created by yaning.
 * School: HUST
 * Email: wangyaning6166@gmail.com
 */
public class _035Index {
    static class Solution {
        public int searchInsert(int[] nums, int target) {
            int index = -1;
            while (++index < nums.length && target > nums[index]);
            return index;
        }
    }
}
