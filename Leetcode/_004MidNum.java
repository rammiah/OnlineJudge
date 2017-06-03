package Leetcode;

/**
 * Created by yaning on 17-6-3.
 */
public class _004MidNum {
    static class Solution {
        // 思路是新建一个数组放进去所有元素，可是不能满足时间要求O(log(m+n))。
        public double findMedianSortedArrays(int[] nums1, int[] nums2) {
            int[] sum = new int[nums1.length + nums2.length];
            int index1 = 0;
            int index2 = 0;
            int indexSum = 0;
            // 复制数据
            while (index1 < nums1.length && index2 < nums2.length) {
                if (nums1[index1] < nums2[index2]) {
                    sum[indexSum++] = nums1[index1++];
                } else {
                    sum[indexSum++] = nums2[index2++];
                }
            }
            while (index1 < nums1.length) {
                sum[indexSum++] = nums1[index1++];
            }
            while (index2 < nums2.length) {
                sum[indexSum++] = nums2[index2++];
            }
            // 开始处理
            int mid = indexSum / 2;
            // [1, 2, 3, 4, 5, 6] indexSum 比length大1
            // 正好奇数个元素的话
            if (sum.length % 2 == 1) {
                return 1.0 * sum[mid];
            }
            else {
                // 随便写个例子就知道啦
                return (sum[mid] + sum[mid - 1]) * 0.5;
            }
        }
    }
}
