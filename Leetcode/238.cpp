class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 1);
        int front = 1;
        int back = 1;
        for (int i = 0; i < size; ++i) {
            res[i] *= front;
            front *= nums[i];
            res[size - 1 - i] *= back;
            back *= nums[n - i - 1];
        }

        return res;
    }
};