/*************************************************************************
	> File Name: 2And3Hash.cpp
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年06月03日 星期六 23时00分10秒
 ************************************************************************/

#include <cstdio>
#include <cstdlib>

int HASH[50001];

void Init() {
    srand(1000);
    for (int i = 0; i <= 50000; ++i) {
        HASH[i] = rand() * rand();
    }
}

int get_hash(int*arr, int len) {
    int hash = 0;
    for (int i = 0; i < len; ++i) {
        hash += HASH[arr[i]];
    }
    return hash;
}

int main(void) {
    Init();
    int key_hash = 0;
    int temp_hash = 0;
    int length = 0;
    scanf("%d", &length);
    int *key = (int *) malloc(length * sizeof(int));
    for (int i = 0; i < length; ++i) {
        scanf("%d", &key[i]);
    }
    int ask = 0;
    scanf("%d", &ask);
    int temp_len = 0;
    int sol = 0;
    int temp = 0;
    for (int i = 0; i < ask; ++i) {
        scanf("%d", &temp_len);
        temp_hash = 0;
        for (int j = 0; j < temp_len; ++j) {
            scanf("%d", &temp);
            temp_hash += HASH[temp];
        }
        sol = 0;
        key_hash = get_hash(key, temp_len);
        for (int j = 0; j <= length - temp_len; ++j) {
            if (j != 0) {
                key_hash = key_hash - HASH[key[j - 1]] + HASH[key[j + temp_len - 1]];
            }
            if (key_hash == temp_hash) {
                sol++;
            }
        }
        printf("%d\n", sol);
    }
    return 0;
}

