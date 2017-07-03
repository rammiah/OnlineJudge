package Leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by yaning on 17-6-4.
 */
public class _011MaxArea {

    public static void main(String[] args) {
        int[] height = new int[15000];
        for (int i = 0; i < height.length; i++) {
            height[i] = i + 1;
        }
        System.out.println(new Solution().maxArea(height));
    }


    static class Solution {
        public int maxArea(int[] height) {
            int max = 0;
            int left = 0;
            int right = height.length - 1;
            int area;
            int temp_index;
            while (left < right) {
                area = (right - left) * (height[left] > height[right] ? height[right] : height[left]);
                max = area > max ? area : max;
                if (height[left] > height[right]) {
                    temp_index = right - 1;
                    while (temp_index > left && height[temp_index] <= height[right]) {
                        --temp_index;
                    }
                    right = temp_index;
                } else {
                    temp_index = left + 1;
                    while (temp_index < right && height[temp_index] <= height[left]){
                        ++left;
                    }
                    left = temp_index;
                }
            }

            return max;
        }
    }
}
