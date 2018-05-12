#include <cstdio>

int main() {
    const int big = 1, small = 0;
    int value = 0, times = 0;
    scanf("%d %d", &value, &times);

    int put = 0, choise = 0;
    int n1 = 0, n2 = 0;
    bool win = false;

    for (int i = 0; i < times; ++i) {
        
        scanf("%d %d %d %d", &n1, &choise, &put, &n2);
        if (put > value) {
            printf("Not enough tokens.  Total = %d.\n", value);
            continue;
        }
        win = (choise == big) && (n1 < n2) || (choise == small) && (n1 > n2);
        value += win ? put : -put;
        if (win) {
            printf("Win %d!  Total = %d.\n", put, value);
        } else {
            printf("Lose %d.  Total = %d.\n", put, value);
            if (value == 0) {
                printf("Game Over.\n");
                break;
            }
        }
    }

    return 0;
}
