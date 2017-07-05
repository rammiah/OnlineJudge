class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        // 好吧，题里是没说k比len小
        k %= len;
        int*nums_cpy = new int[len];
        for (int i = 0; i < len; ++i) {
            nums_cpy[i] = nums[(i + len - k) % len];
        }
        for (int i = 0; i < len; ++i) {
            nums[i] = nums_cpy[i];
        }
    }
};