#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int graph[1005][1005] = {0};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int x = 0, y = 0;
	int d = 0;
	graph[0][0] = 1;
	while (m > 0) {
		switch (d) {
			case 0:
				if (x == n - 1 || graph[x + 1][y] == 1) {
					d = 1;
					y++;
				}
				else {
					x++;
				}
				break;
				
			case 1:
				if (y == n - 1 || graph[x][y + 1] == 1) {
					d = 2;
					x--;
				}
				else {
					y++;
				}
				break;
			case 2:
				if (x == 0 || graph[x - 1][y] == 1) {
					d = 3;
					y--;
				}
				else {
					x--;
				}
				break;
			case 3:
				if (y == 0 || graph[x][y - 1] == 1) {
					d = 0;
					x++;
				}
				else {
					y--;
				}
				break;
		}
		graph[x][y] = 1;
		m--;
	}
	printf("%d %d\n", x + 1, y + 1);

    return 0;
}
