#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0;
        int rest = 0;
        int hold = INT_MIN;
        // 评论区到处都是人才，知道是DP但是不知道怎么写，😔
        for (auto &price : prices) {
            int prev_sold = sold;
            sold = hold + price;
            hold = max(hold, rest - price);
            rest = max(rest, prev_sold);
        }
        return max(rest, sold);
    }
};