public class Solution {
    // 寻找下一个排列，就是排列组合里的全排列的下一个
    public void nextPermutation(int[] nums) {
        if (nums == null || nums.length <= 1)return;
        // 一开始没看懂题，Google了一下知道什么意思了，先找已经全排的第一个下标，
        int done = 0;
        int len = nums.length;
        for (int i = len - 1; i >= 1; --i) {
            if (nums[i] > nums[i - 1]) {
                done = i;
                break;
            }
        }
        // 说明已经到头了
        if (done == 0) {
            reverse(nums, 0, len - 1);
            return;
        }
        // 选择已全排前一个
        int to_move = done - 1;
        int to_move1 = 0;
        // 寻找交换的
        for (to_move1 = len - 1; to_move1 > to_move; --to_move1) {
            if (nums[to_move1] > nums[to_move]) {
                break;
            }
        }
        // 交换一下
        int t = nums[to_move];
        nums[to_move] = nums[to_move1];
        nums[to_move1] = t;
        reverse(nums, to_move + 1, len - 1);
    }
    // 翻转的函数
    private void reverse(int[] arr, int begin, int end) {
        int t = 0;
        while (begin < end) {
            t = arr[begin];
            arr[begin] = arr[end];
            arr[end] = t;
            ++begin;
            --end;
        }
    }
}
