/*************************************************************************
	> File Name: 1070Rope.c
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年05月23日 星期二 11时00分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

void Sort(int*arr, int start, int end){
    if (start >= end){
         return;
    }
    int key = arr[start];
    int s = start;
    int e = end;
    while (s < e){
        while (arr[e] <= key && s < e)--e;
        arr[s] = arr[e];
        while (arr[s] >= key && s < e)++s;
        arr[e] = arr[s];
    }
    arr[e] = key;
    Sort(arr, start, s - 1);
    Sort(arr, s + 1, end);
}

void Insert(int*ropes, int todo_index){
    int temp = ropes[todo_index];
    int i = todo_index - 1;
    while (i >= 0 && ropes[i] <= temp){
        ropes[i + 1] = ropes[i];
        i--;
    }
    ropes[i + 1] = temp;
}

int main(void){
    int sum = 0;
    scanf("%d", &sum);

    int* ropes = (int*)malloc(sum * sizeof(int));

    for (int i = 0; i < sum; ++i){
        scanf("%d", &ropes[i]);
    }

    Sort(ropes, 0, sum - 1);
    for (int i = sum - 1; i >0; --i){
        ropes[i - 1] = (ropes[i - 1] + ropes[i]) / 2;
        Insert(ropes, i - 1);
    }
    printf("%d\n", ropes[0]);
    free(ropes);
    return 0;
}

