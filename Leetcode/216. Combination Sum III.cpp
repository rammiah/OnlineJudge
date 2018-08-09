#include <vector>

using namespace std;

class Solution {
    int depth = 0;
    void dfs(vector<vector<int>> &result, vector<int> &tmp,int idx, int d, int sum, int target) {
        if (sum > target) {
            return;
        }
        if (d == depth) {
            if (sum == target) {
                result.push_back(tmp);
            }
        }
        for (int i = idx + 1; i <= 9; ++i) {
            if (sum + i > target) {
                break;
            }
            tmp.push_back(i);
            dfs(result, tmp, i, d + 1, sum + i, target);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        depth = k;
        vector<int>  tmp;
        vector<vector<int>> result; 
        dfs(result, tmp, 0, 0, 0, n);
        return result;
    }
};