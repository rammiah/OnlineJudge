/*************************************************************************
	> File Name: Signal.c
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年06月04日 星期日 20时51分55秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>


int main() {
    int strength = 0;
    scanf("%d", &strength);
    printf("+-----+\n");
    if (strength >= 90) {
        printf("|-  4G|\n");
    } else if (strength >= 60) {
        printf("|-  3G|\n");
    } else if (strength >= 20) {
        printf("|-   E|\n");
    } else {
        printf("|    E|\n");
    }

    if (strength == 100) {
        printf("|--   |\n");
        printf("|---  |\n");
        printf("|---- |\n");
        printf("|-----|\n");
    } else if (strength >= 80) {
        printf("|--   |\n");
        printf("|---  |\n");
        printf("|---- |\n");
        printf("|     |\n");
    } else if (strength >= 60) {
        printf("|--   |\n");
        printf("|---  |\n");
        printf("|     |\n");
        printf("|     |\n");
    } else if (strength >= 40) {
        printf("|--   |\n");
        printf("|     |\n");
        printf("|     |\n");
        printf("|     |\n");
    } else {
        printf("|     |\n");
        printf("|     |\n");
        printf("|     |\n");
        printf("|     |\n");
    }

    printf("+-----+");

    return 0;
}

