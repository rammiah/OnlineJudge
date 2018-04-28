void update(int &a, int b) {
    a = max(a, b);
}

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int max_len = 1;
        int temp_len = 1;
        int len = nums.size();
        int last = nums[0];
        for (int i = 1; i < len; ++i) {
            if (nums[i] == last + 1) {
                ++temp_len;
                update(max_len, temp_len);
            } else if (nums[i] != last) {
                // 0, 0 ans = 1, 0, 1, 1, 2 ans = 3
                temp_len = 1;
            }
            
            last = nums[i];
        }


        return max_len;
    }
};
