class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // 查找所有可以凑成三角形的边的组合
        sort(nums.begin(), nums.end());
        int result = 0;

        for (int k = nums.size() - 1; k > 1; --k) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    result += --j - i + 1;
                }
                else {
                    ++i;
                }
            }
        }

        return result;
    }
};