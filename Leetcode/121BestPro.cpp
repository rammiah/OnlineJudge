ass Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;         // 最大利润
        int tempPro = 0;        // 当前利润
        int minPri = INT_MAX;   // 最小买入价格
        for (int i = 0; i < prices.size(); ++i) {
            // 更新当前利润
            tempPro = prices[i] - minPri;
            // 更新最大利润
            maxPro = tempPro > maxPro ? tempPro : maxPro;
            // 更新当前最小价
            minPri = prices[i] < minPri ? prices[i] : minPri;
        }
        return maxPro;
    }
};
