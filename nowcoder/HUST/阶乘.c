#include <stdio.h>

int main() {
    int n;
    int y1, y2, fat;
    while (~scanf("%d", &n)) {
        fat = 1;
        y1 = y2 = 0;
        for (int i = 1; i <= n; ++i) {
            fat *= i;
            if (i & 1) {
                y1 += fat;
            } else {
                y2 += fat;
            }
        }
        printf("%d %d\n", y1, y2);
    }
    
    return 0;
}