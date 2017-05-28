/*************************************************************************
	> File Name: 198MaxRobery.c
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年05月28日 星期日 14时17分10秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define max(a, b) ((a)>(b)?(a):(b))
int rob(int num[], int n) {
    int a = 0;
    int b = 0;
    
    for (int i=0; i<n; i++)
    {
        if (i%2==0)
        {
            a = max(a+num[i], b);
        }
        else
        {
            b = max(a, b+num[i]);
        }
    }
    
    return max(a, b);
}
