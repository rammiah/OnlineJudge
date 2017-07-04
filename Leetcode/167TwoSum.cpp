#include <vector>
using std::vector;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        int sum = 0;
        // 妙啊，夹挤，厉害
        while (low < high) {
            sum = numbers[low] + numbers[high];
            if (sum > target) {
                hight--
            } else if (sum < target) {
                low++;
            } else {
                return {low + 1, high + 1};
            }
        }
        return {-1,-1};
    }
};