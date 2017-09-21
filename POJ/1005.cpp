#include <cstdio>

const double PI = 3.1415926;

// 获取开始腐蚀的日期
int getDeadline(const double &x, const double &y) {
    double area = PI * (x * x + y * y) / 2;
    int t = (int)area / 50;
    // 小于才进去加一，大于等于可以输出了
    if (t * 50 < area) {
        return t + 1;
    }
    return t;
}

int main() {
    int index = 0;
    int count = 0;
    double x = 0, y = 0;
    scanf("%d", &count);
    for (index = 1; index <= count; ++index) {
        scanf("%lf %lf", &x, &y);
        printf("Property %d: This property will begin eroding in year %d.\n", index, getDeadline(x, y));
    }
    printf("END OF OUTPUT.\n");
    
    return 0;
}

/*
2
1.0 1.0
25.0 0
*/

