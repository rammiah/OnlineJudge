class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0; i < len - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                int temp = nums[i + 1];
                nums[i + 1] = nums[i];
                bool sorted = true;
                for (int j = 0; j < len - 1; ++j) {
                    if (nums[j] > nums[j + 1]) {
                        sorted = false;
                        break;
                    }
                }
                if (sorted) return true;
                nums[i] = nums[i + 1] = temp;
                for (int j = 0; j < len - 1; ++j) {
                    if (nums[j] > nums[j + 1]) {
                        return false;
                    }
                }
                return true;
            }
        }

        return true;
    }
};