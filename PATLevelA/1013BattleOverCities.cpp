#include <stdio.h>
#include <memory.h>
#define MAX 2000

int N, M, K;
int mat[MAX][MAX];
int visit[MAX];

void dfs(int from) {
	int i;
	for (i = 1; i <= N; i++) {
		if (visit[i] == 0 && mat[from][i] == 1) {
			visit[i] = 1;
			dfs(i);
		}
	}
}

int main() {
	int i, j;
	int s, e;
	scanf("%d %d %d", &N, &M, &K);

	memset(mat, 0, sizeof(mat));
	for (i = 0; i<M; i++) {
		scanf("%d %d", &s, &e);
		mat[s][e] = mat[e][s] = 1;
	}

	int city;
	for (i = 0; i<K; i++) {
		scanf("%d", &city);
		memset(visit, 0, sizeof(visit));
		visit[city] = 1;
		int count = 0;
		for (j = 1; j <= N; j++) {
			if (visit[j] == 0) {
				count++;
				dfs(j);
			}
		}
		printf("%d\n", count - 1);
	}
	return 0;
}