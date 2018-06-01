#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int m, n;
    int blks;
    scanf("%d", &blks);
    int id;
    while (blks--) {
        id = 1;
        scanf("%d %d", &n, &m);
        while (m != 0 || n != 0) {
            int result = 0;
            for (int b = 2; b < n; ++b) {
                for (int a = 1; a < b; ++a) {
                    if ((a * a + b * b + m) % (a * b) == 0) {
                        ++result;
                    }
                }
            }
            printf("Case %d: %d\n", id++, result);
            scanf("%d %d", &n, &m);
        }
        printf("%s", (blks == 0 ? "" : "\n"));
    }

    return 0;
}