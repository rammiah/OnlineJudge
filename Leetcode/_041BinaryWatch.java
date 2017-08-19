import java.util.ArrayList;
import java.util.List;

class Solution {
    // 二进制数字钟表，使用递归思路很清晰
    public List<String> readBinaryWatch(int num) {
        List<String> result = new ArrayList<>();
        search(result, 0, 0, 0, num);
        return result;
    }

    private void search(List<String> result, int hours, int minutes, int index, int left) {
        if (left == 0) {
            if (hours <= 11 && minutes <= 59) {
                result.add(String.format("%d:%02d", hours, minutes));
            }
            return;
        }
        // 如果有不满足的就返回
        if (index > 9 || hours > 11 || minutes > 59) {
            return;
        }

        for (int i = index; i < 10; i++) {
            if (i > 3) {
                search(result, hours, minutes + (1 << (i - 4)), i + 1, left - 1);
            } else {
                search(result, hours + (1 << i), minutes, i + 1, left - 1);
            }
        }
    }
}
