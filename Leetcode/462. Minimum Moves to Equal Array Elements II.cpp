using ll = long long;

class Solution {
public:
    int minMoves2(vector<int> &nums) {
        // minimum move to let the array equal
        sort(nums.begin(), nums.end());
        int result = 0;
        // mid number
        int mid = nums[nums.size() / 2];
        for (const auto &t : nums) {
            result += abs(t - mid);
        }

        return result;
    }
};

