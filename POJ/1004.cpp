#include <cstdio>

// woc，居然这么简单，不可思议啊
int main() {
    double temp = 0;
    double sum = 0;
    int months = 12;
    for (int i = 0; i < months; ++i) {
        scanf("%lf", &temp);
        sum += temp;
    }

    printf("$%.2f\n", sum / months);

    return 0;
}

/*
100.00
489.12
12454.12
1234.10
823.05
109.20
5.27
1542.25
839.18
83.99
1295.01
1.75
*/

