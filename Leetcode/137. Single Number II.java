import java.util.HashMap;
import java.util.HashSet;

class Solution {
    // 要说难也不难，就是不好提升
    public int singleNumber(int[] nums) {
        // 扫描nums
        // 将每个数字记录
        long sum = 0;
        long set_sum = 0;
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            if (set.add(num)) {
                set_sum += num;
            }
            sum += num;
        }

        return (int)((3 * set_sum - sum)>>1);
    }
}
