public class Solution {
    public int search(int[] nums, int target) {
        // 使用Java一定要注意判断是否为空指针
        if (nums == null)return -1;
        int l = 0, r = nums.length - 1;
        int mid = 0;
        while (l <= r) {
            mid = (r + l) / 2;//不管那么多了
            if (nums[mid] == target) {
                return mid;
            }

            if (nums[mid] >= nums[l]) {
                if (target < nums[mid]
                        && target >= nums[l]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }

            if (nums[mid] <= nums[r]) {
                if (target > nums[mid]
                        && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
}
