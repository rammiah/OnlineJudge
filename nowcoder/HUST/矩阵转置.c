#include <stdio.h>
#define MAXN 105

int mat[MAXN][MAXN];

int main(void) {
    int cnt = 0;
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            scanf("%d", &mat[j][i]);
        }
    }
    
    for (int i = 0; i < cnt; ++i) {
        for (int j = 0; j < cnt; ++j) {
            printf("%d%c", mat[i][j], j == cnt - 1 ? '\n' : ' ');
        }
    }
    
    return 0;
}
