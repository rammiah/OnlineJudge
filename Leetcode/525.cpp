class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int size = nums.size(), ballance = size, max_len = 0;
        int ballances[size * 2 + 1] = {};
        // dp??看不懂啊
        for (auto i = 0; i < size; ++i) {
            ballance += nums[i] == 0 ? -1 : 1;
            if (ballance == size) max_len = i + 1;
            else {
                if (ballances[ballance] != 0) {
                    max_len = max(max_len, i - ballances[ballance] + 1);
                }
                else {
                    ballances[ballance] = i + 1;
                }
            }
        }

        return max_len;
    }
};