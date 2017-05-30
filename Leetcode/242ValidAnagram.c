/*************************************************************************
	> File Name: 242ValidAnagram.c
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年05月30日 星期二 20时59分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

bool isAnagram(char* s, char* t) {
    int arr1[26] = { 0,  };
    int arr2[26] = { 0,  };
    int len = 0;
    if ((len = strlen(s)) != strlen(t))return false;
    for (int i = 0; i < len; ++i) {
        ++arr1[s[i] - 'a'];
        ++arr2[t[i] - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
        if (arr1[i] != arr2[i])return false;
    }
    return true;
}

int main(void) {
    char s[8] = "anagram";
    char t[8] = "nagaram";
    printf("%d\n", isAnagram(s, t));


    return 0;
}
