class NumArray {
public:
    vector<int>sum;
    NumArray(vector<int> nums) {
        int t = 0;
        sum.push_back(0);
        for (int i = 0; i < nums.size(); ++i) {
            t += nums[i];
            sum.push_back(t);
        }
    }
    // 0, 0
    // 0, 1
    int sumRange(int i, int j) {
        return sum[j + 1] - sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */