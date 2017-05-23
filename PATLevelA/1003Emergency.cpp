#include<cstdio>
#include<cstring>

#define INF 0x7FFFFF
int u[502] = { 0 }; // 记录是否遍历了，1已遍历，0未遍历
int teams[502] = { 0 }; // 记录队伍
int dist[502]; // 记录距离
int mp[502][502]; // 记录图
int n, m, st, en;
int shortNum = 0, maxteam = 0, mindist = INF;

void dfs(int s, int dis, int team) {//开始点，到达S结点时的距离，teams
	// 如果到了终点
	if (s == en) {
		if (dis<mindist) {
			mindist = dis;
			shortNum = 1; //这个最短，以前的舍去
			maxteam = team; //
		}
		// 如果距离和最短的一样
		else if (dis == mindist) {
			shortNum++;
			if (team>maxteam) maxteam = team;
		}
		return;
	}
	u[s] = 1; // 设置为已遍历
	// 再次遍历未便利的结点，在这个结点的递归中不应该再遍历此节点
	for (int i = 0; i<n; i++) {
		// 如果未遍历且存在路
		if (u[i] == 0 && mp[s][i]>0) {
			dfs(i, dis + mp[s][i], team + teams[i]);
		}
	}
	u[s] = 0; //置为可以遍历状态
}

int main() {
	int i;
	scanf("%d %d %d %d", &n, &m, &st, &en);
	for (i = 0; i<n; i++) scanf("%d", &teams[i]);
	memset(mp, -1, sizeof(mp));
	for (i = 0; i<m; i++) {
		int t1, t2, dis;
		scanf("%d %d %d", &t1, &t2, &dis);
		mp[t1][t2] = mp[t2][t1] = dis;
	}

	//u[st]=1;
	dfs(st, 0, teams[st]);

	printf("%d %d\n", shortNum, maxteam);
	return 0;
}
