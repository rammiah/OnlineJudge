import java.util.Arrays;

class Solution {
    public int firstMissingPositive(int[] nums) {
        // 判断空引用或者长度为0
        if (nums == null || nums.length == 0) return 1;
        Arrays.sort(nums);
        int index = 0;
        int len = nums.length;
        // 找到第一个大于0的
        while (index < len && nums[index] <= 0) ++index;
        // 全部小与0
        if (index == len) {
            return 1;
        }
        // 第一个整数大于1
        else if (nums[index] > 1) {
            return 1;
        }
        // 寻找数字
        while (index < len - 1 &&
                (nums[index] + 1 == nums[index + 1] || nums[index] == nums[index + 1])) ++index;
        // 不缺少数字
        if (index == len) {
            return nums[index - 1] + 1;
        }
        // 缺一个数字
        else {
            return nums[index] + 1;
        }
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {3};
        System.out.println(solution.firstMissingPositive(nums));
    }
}

