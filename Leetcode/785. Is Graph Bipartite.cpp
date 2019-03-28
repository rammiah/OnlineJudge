#define N 105

class Solution {
    bool visited[N];
    char mark[N];

    bool dfs(char ch, int vertex, vector<vector<int>> &g) {
        // 遍历过的不再进行
        if (visited[vertex]) {
            return true;
        }
        // 设置遍历为true
        visited[vertex] = true;
        mark[vertex] = ch;
        // 替换
        ch = 1 - ch;
        for (auto &v : g[vertex]) {
            if (!visited[v]) {
                // 递归进行检测
                if (!dfs(ch, v, g)) {
                    return false;
                }
            } else if (mark[v] == mark[vertex]) {
                return false;
            }
        }
        return true;
    }


public:
    bool isBipartite(vector<vector<int>> &graph) {
        // 判断是否是二分图
        bzero(mark, sizeof(mark));
        memset(visited, 0, sizeof(visited));
        // 上色问题
        for (int i = 0; i < graph.size(); ++i) {
            // 最简单的递归算法哈
            if (!visited[i] && !dfs(0, i, graph)) {
                return false;
            }
        }
        return true;
    }
};

