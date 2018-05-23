#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_cp(nums);
        // 简单直接粗暴嘿嘿嘿
        sort(nums_cp.begin(), nums_cp.end());
        int size = nums.size();
        int result = size;
        int left = 0, right = size - 1;
        while(left < size && nums[left] == nums_cp[left]) {
            ++left;
            --result;
        }
        // 防止数据已经有序使用left作为停止边界
        while (right >= left && nums[right] == nums_cp[right]) {
            --right;
            --result;
        }

        return result;
    }
};