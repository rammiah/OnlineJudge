#include <map>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int N, szDown[MAXN], sumDown[MAXN];
map<int,int> ansMap;
VI adj[MAXN];
PII dfsDown(int x, int p) {
  // 子节点个数，子孙节点个数
  int szdown = 0, sumdown = 0;
  REP(i,0,adj[x].size()) {
    int y = adj[x][i];
    if (y == p) continue;
    PII res = dfsDown(y, x);
    szdown += res.first;
    sumdown += res.second;
  }
  sumdown += szdown;
  szdown++;
  szDown[x] = szdown;
  sumDown[x] = sumdown;
  return PII(szdown, sumdown);
}

void dfsAns(int x, int p, int szTop, int sumTop) {
  ansMap[x] = sumTop + szTop + sumDown[x];
  REP(i,0,adj[x].size()) {
    int y = adj[x][i];
    if (y == p) continue;
    int sz = szDown[0] - szDown[y];
    int sum = sumTop + szTop + (sumDown[x] - sumDown[y] - szDown[y]);
    dfsAns(y, x, sz, sum);
  }
}

class Solution {
public:
  vector<int> sumOfDistancesInTree(int _N, vector<vector<int>>& edges) {
    N = _N;
    ansMap.clear();
    REP(i,0,N) adj[i].clear();
    REP(i,0,edges.size()) {
      int x = edges[i][0], y = edges[i][1];
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    dfsDown(0, -1);
    dfsAns(0, -1, 0, 0);
    VI ans;
    for (auto it = ansMap.begin(); it != ansMap.end(); it++) ans.push_back(it->second);
    return ans;
  }
};
