#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) {
            return 0;
        }
        int result = 0;
        // 存储0到当前位置和
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = 1;
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            sum += nums[i];
            result += m[sum - k];
            ++m[sum];
        }

        return result;
    }
};