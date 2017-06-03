/*************************************************************************
	> File Name: 1Hubs.cpp
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年06月03日 星期六 19时28分02秒
 ************************************************************************/

//
// Created by yaning on 17-6-3.
//

#include <cstdio>
#include <cstdlib>

void QuickSort(int *arr, int start, int end) {
    if (start >= end) {
        return;
    }
    int key = arr[start];
    int s = start;
    int e = end;
    while (s < e) {
        while (arr[e] <= key && s < e)--e;
        arr[s] = arr[e];
        while (arr[s] >= key && s < e)++s;
        arr[e] = arr[s];
    }
    arr[s] = key;
    QuickSort(arr, start, s - 1);
    QuickSort(arr, s + 1, end);
}


int main(void) {
    int sum_Dev = 0;
    int sum_hub = 0;
    int valid = 0;
    scanf("%d %d", &sum_Dev, &sum_hub);
    int *hubs = (int *) malloc(sum_hub * sizeof(int));
    for (int i = 0; i < sum_hub; ++i) {
        scanf("%d", &hubs[i]);
    }
    QuickSort(hubs, 0, sum_hub - 1);
    int sum_interf = 0;
    for (int i = 0; i < sum_hub && hubs[i] >= 2; ++i) {
        sum_interf += hubs[i];
        ++valid;
    }
    int sol = -1;
    if (sum_interf + 1 - valid  >= sum_Dev) {
        sol = 0;
        while (sum_Dev > 1) {
            sum_Dev -= hubs[sol++];
            sum_Dev++;
        }
    }
    if (sol == -1) {
        printf("Impossible");
    } else{
        printf("%d\n", sol);
    }

    free(hubs);
    return 0;
}
