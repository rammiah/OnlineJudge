#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// 能够减少每个的计算个数就好了
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        // 嵌套的有点多
        // 优先队列最大的在前面
        priority_queue<pair<double, pair<int,int>>>pq;
        for(int i = 0; i < A.size(); i++){
            // 第二个pair里存放下标
            pq.push({-1.0 * A[i] / A.back(), {i, A.size() - 1}});
        }

        while(--K > 0) {
            pair<int,int> cur = pq.top().second;
            pq.pop();
            cur.second--;
            pq.push({-1.0 * A[cur.first] / A[cur.second], {cur.first, cur.second}});
        }
        return {A[pq.top().second.first], A[pq.top().second.second]};
    }
};