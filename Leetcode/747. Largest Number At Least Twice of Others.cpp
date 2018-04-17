class Solution {
    void update(int &a, int b) {
        a = a > b ? a : b;
    }
public:

    int dominantIndex(vector<int>& nums) {
        int max = 0;

        for (int &num : nums) {
            update(max, num);
        }      
        int size = nums.size();
        int idx = 0;
        for (int i = 0; i < size; ++i) {
            if (nums[i] * 2 > max) {
                if (nums[i] == max) {
                    idx = i;
                }else{
                    return -1;
                }
            }
        }

        return idx;
    }
};