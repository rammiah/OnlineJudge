// 075 sort colors maybe quick sort can be useful
class Solution {
    private static final int RED = 0, WHITE = 1, BLUE = 2;

    void quickSort(int[] array, int left, int right) {
        if (left >= right) return;
        int key = array[left];
        int l = left;
        int r = right;
        while (l < right) {
            while (l < r && array[r] >= key)r--;
            array[l] = array[r];
            while (l < r && array[l] <= key)l++;
            array[r] = array[l];
        }
        array[l] = key;
        quickSort(array, left, l - 1);
        quickSort(array, l + 1, right);
    }

    public void sortColors(int[] nums) {
//        int left = 0, right = nums.length - 1;
//        int redCount = 0, whiteCount = 0, blueCount = 0;
//        for (int num : nums) {
//            switch (num) {
//                case RED:
//                    ++redCount;
//                    break;
//                case WHITE:
//                    ++whiteCount;
//                    break;
//                case BLUE:
//                    ++blueCount;
//                    break;
//                default:
//                    throw new IllegalArgumentException();
//            }
//        }
//        for (int i = 0; i < redCount; i++) {
//            nums[i] = RED;
//        }
//        for (int i = redCount; i < redCount + whiteCount; i++) {
//            nums[i] = WHITE;
//        }
//        for (int i = redCount + whiteCount; i < redCount + whiteCount + blueCount; i++) {
//            nums[i] = BLUE;
//        }
        // 显然就是个排序，直接快排也行，从小到大排
        quickSort(nums, 0, nums.length - 1);
    }
}
