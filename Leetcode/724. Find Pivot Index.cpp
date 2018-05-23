#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0) {
            return -1;
        } else if (nums.size() == 1) {
            return 0;
        }
        long long left_sum = 0, right_sum = 0;
        for (auto &num : nums) {
            right_sum += num;
        }
        int pivot = 0;
        right_sum -= nums[pivot];
        int len = nums.size();
        while (left_sum != right_sum && pivot < len - 1) {
            left_sum += nums[pivot];
            right_sum -= nums[pivot + 1];
            pivot++;
        }

        return left_sum == right_sum ? pivot : -1;
    }
};
