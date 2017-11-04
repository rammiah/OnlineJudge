#include <stdio.h>

/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；

A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；

A3 = 被5除后余2的数字的个数；

A4 = 被5除后余3的数字的平均数，精确到小数点后1位；

A5 = 被5除后余4的数字中最大数字。

输入描述:
每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。


输出描述:
对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。
*/

int main(void) {
    int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    float a4 = 0;
    
    int cnt = 0;
    int a2_cnt = 0;
    int a4_cnt = 0;

    scanf("%d", &cnt);
    int num = 0;
    for (int i = 0; i < cnt; ++i) {
        scanf("%d", &num);
        switch (num % 5) {
            case 0:
                if (num % 2 == 0) {
                    a1 += num;
                }
                break;
            case 1:
                a2 += a2_cnt % 2 == 0 ? num : -num;
                ++a2_cnt;
                break;
            case 2:
               ++a3;
               break;
            case 3:
                a4 += num;
                ++a4_cnt;
                break;
            case 4:
                a5 = a5 < num ? num : a5;
                break;
            default:
                break;
        }
    }
    // printf("%d ", a1 == 0 ? 'N')
    if (a1 == 0) {
        printf("N ");
    } else {
        printf("%d ", a1);
    }

    if (a2_cnt == 0) {
        printf("N ");
    } else {
        printf("%d ", a2);
    }

    printf("%d ", a3);

    if (a4_cnt == 0) {
        printf("N ");
    } else {
        printf("%.1f ", a4 / a4_cnt);
    }

    if (a5 == 0) {
        printf("N\n");
    } else {
        printf("%d\n", a5);
    }

    return 0;
}
