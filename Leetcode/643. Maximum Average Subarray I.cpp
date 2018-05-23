class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, result;
        for (int i = 0; i < k; ++i) {
            sum += nums[i];
        }
        result = sum;
        int size = nums.size();
        for (int i = k;i < size; ++i) {
            sum += nums[i] - nums[i - k];
            result = result > sum ? result : sum;
        }

        return result / k;
    }
};