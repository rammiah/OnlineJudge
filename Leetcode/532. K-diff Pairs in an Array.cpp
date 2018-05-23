#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (nums.size() <= 1) {
            return 0;
        }
        unordered_set<long long> nums_set, result_set;
        vector<int> nums_cp(nums);
        sort(nums_cp.begin(), nums_cp.end());
        nums_set.insert(nums_cp[0]);
        int size = nums_cp.size();
        //50ms
        for (int i = 1; i < size; ++i) {
            if (nums_set.count(nums_cp[i] - k)) {
                result_set.insert((nums_cp[i] - k) * 1E10 + nums_cp[i]);
            }
            nums_set.insert(nums_cp[i]);
        }
        return result_set.size();
    }
};