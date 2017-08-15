public class Solution {
    // 给一个容器，接雨水
    public int trap(int[] height) {
        if (height == null || height.length <= 2)return 0;
        int sum = 0;
        int min = 0;
        int maxIndex = 0;
        for (int i = 0; i < height.length; ++i) {
            if (height[i] > height[maxIndex]) {
                maxIndex = i;
            }
        }
        // left to maxIndex
        for (int i = 0; i < maxIndex; i++) {
            if (height[i] > min) {
                min = height[i];
            }
            else {
                sum += min - height[i];
            }
        }
        min = 0;
        // right to maxIndex
        for (int i = height.length - 1; i > maxIndex; --i) {
            if (height[i] > min) {
                min = height[i];
            }
            else {
                sum += min - height[i];
            }
        }
        return sum;
    }
}
