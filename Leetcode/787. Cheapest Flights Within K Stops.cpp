#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        static const int kInf = 1e9;
        vector<int> prices(n, kInf);
        prices[src] = 0;
        // 类似Floyd算法，一直更新
        for (int j = 0; j <= K; ++j) {
            vector<int> next_prices = prices;
            for (const auto& flight : flights) {
                int from = flight[0], to = flight[1], price = flight[2];
                next_prices[to] = min(next_prices[to], prices[from] + price);
            }

            prices.swap(next_prices);
        }

        return prices[dst] == kInf ? -1 : prices[dst];
    }
};