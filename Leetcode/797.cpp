
using namespace std;
bool g[15][15];
int size = 0;
class Solution {
public:
    void DFS(vector<vector<int>>& results,
             vector<int> temp, int current, int target) {
        if (current == target) {
            results.push_back(temp);
            return;
        }

        for (int i = 0; i < size; ++i) {
            if (g[current][i]) {
                temp.push_back(i);
                DFS(results, temp, i, target);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        size = graph.size();
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                g[i][j] = false;
            }
            for (int j = 0; j < graph[i].size(); ++j) {
                g[i][graph[i][j]] = true;
            }
        }
        vector<int> temp;
        vector<vector<int>> results;
        temp.push_back(0);
        DFS(results, temp, 0, size - 1);

        return results;
    }
};