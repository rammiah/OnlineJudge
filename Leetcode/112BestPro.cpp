class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPri = 0;
        if (prices.size() > 0) {
            minPri = prices[0];
        } else{
            return 0;
        }
        int len = prices.size();
        int sum = 0;
        int tempPro = 0;
        for (size_t i = 0; i < len - 1; i++) {
            // 其实也不算动态规划了，就是很简单的思路，最大差的和
            if (prices[i + 1] < prices[i]) {
                tempPro = prices[i] - minPri;
                sum += tempPro > 0 ? tempPro : 0;
                minPri = prices[i + 1];
            }
        }
        tempPro = prices[len - 1] - minPri;
        sum += tempPro > 0 ? tempPro : 0;
        return sum;
    }
};
