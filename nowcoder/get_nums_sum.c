#include <stdio.h>
#include <math.h>

int main(void) {
    double num = 0;
    int iter_cnt = 0;
    double sum = 0;
    
    while (scanf("%lf %d", &num, &iter_cnt) != EOF) {
        sum = 0;
        for (int i = 0; i < iter_cnt; ++i) {
            sum += num;
            num = sqrt(num);
        }
        printf("%.2f\n", sum);
    }
    
    return 0;
}
