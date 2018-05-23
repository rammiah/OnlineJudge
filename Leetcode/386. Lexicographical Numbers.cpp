#include <vector>

using namespace std;

class Solution {
    vector<int> nums;    
    void dfs(int cur, const int &limit) {
        if (cur > limit) {
            return;
        }
        nums.push_back(cur);
        cur *= 10;
        for (int i = 0; i < 10; ++i) {
            dfs(cur + i, limit);
        }
    }
public:
    vector<int> lexicalOrder(int n) {
        nums.clear();
        nums.reserve(n);
        for (int i = 1; i < min(10, n + 1); ++i) {
            dfs(i, n);
        }
        return nums;
    }
};
