#include <vector>
using namespace std;
int nums_cnt[100000];
class Solution {
public:
    Solution() {
        // 全局变量居然不是初始化为0👿
        memset(nums_cnt, 0, sizeof(nums_cnt));    
    }


    int findDuplicate(vector<int>& nums) {
        for (auto &num : nums) {
            if (nums_cnt[num] == 0) {
                ++nums_cnt[num];
            } else {
                return num;
            }
        }

        return -1;
    }
};
