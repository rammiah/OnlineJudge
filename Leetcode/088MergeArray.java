package Leetcode;

/**
 * Time: 29/06/17 08:27
 * Created by yaning.
 * School: HUST
 * Email: wangyaning6166@gmail.com
 */
public class _088MergeArray {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        while (j >= 0)
            nums1[j] = nums2[j--];
    }
}
