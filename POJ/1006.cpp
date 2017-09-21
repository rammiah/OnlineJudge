#include <cstdio>

int getNextPeak(int start, int p, int e, int x) {
    // 三个周期分别是23 28 33
    // 从+1开始
    // 最大是21252
    for (int i = start + 1; i <= 21252; ++i) {
        if ((i - p) % 23 == 0 && (i - e) % 28 == 0 && (i - x) % 33 == 0) {
            // 要的是差值
            return i - start;
        }
    }
    return 0;
}

int main() {
    int index = 1;
    int strength = 0, emotion = 0, intelli = 0;
    int startDay = 0;
    while (true) {
        scanf("%d %d %d %d", &strength, &emotion, &intelli, &startDay);
        if (strength == -1 && emotion == -1 && intelli == -1 && startDay == -1) break;
        printf("Case %d: the next triple peak occurs in %d days.\n", index++,
               getNextPeak(startDay, strength, emotion, intelli));
    }

    return 0;
}

/*
 * 中国剩余定理，解同余方程组使用
 * #include<cstdio>
using namespace std;

int main()
{
    int p, e, i, d, icase = 0, x;
    while (scanf("%d%d%d%d", &p, &e, &i, &d), ~p)
    {
        x = (5544 * p + 14421 * e + 1288 * i - d + 21252) % 21252;
        if (x == 0) x = 21252;
        printf("Case %d: the next triple peak occurs in %d days.\n", ++icase, x);
    }
    return 0;
}
 * */

