class Solution {
    public boolean canJump(int[] nums) {
        // 改变一下总是好的
        if (nums == null || nums.length <= 1) return true;
        int len = nums.length;
        int max = nums[0];
        int temp = 0;
        for (int i = 0; i < len; i++) {
			// 有戏再继续
            if (i <= max) {
                temp = i + nums[i];
                if (temp > max) {
                    max = temp;
					// 直达终点
                    if (max >= len - 1) {
                        return true;
                    }
                }
            } else {
				// Game over
                return false;
            }
        }

        return true;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {5, 9, 3, 2, 1, 0, 2, 3, 3, 1, 0, 0};
        System.out.println(solution.canJump(nums));
    }
}

