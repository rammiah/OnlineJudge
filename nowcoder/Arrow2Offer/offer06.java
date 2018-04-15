import java.util.ArrayList;
public class Solution {
    public int minNumberInRotateArray(int [] array) {
        if (array == null || array.length == 0) {
            return 0;
        }
        if (array[0] < array[array.length - 1]) {
            return array[0];
        }
        // 懒得想二分查找...
        for (int i = 0; i < array.length - 1; i++) {
            if (array[i] > array[i + 1]) {
                return array[i + 1];
            }
        }
        // 装饰作用
        return 0;
    }
}