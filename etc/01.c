#include <stdio.h>

void print() {
    int t = 0;
    scanf("%d", &t);
    if (t == -1) {
        return;
    }
    print();
    printf("%d ", t);
}

int main(void) {
    print();
    return 0;
}
