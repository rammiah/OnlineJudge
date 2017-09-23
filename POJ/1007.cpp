#include <stdio.h>
#include <stdlib.h>
// POJ的gcc太古老了，哎
// 使用结构体
struct String {
    char *str;
    size_t reverse;
};

// 交换
void swap(struct String array[], size_t a, size_t b) {
    if (a == b) {
        return;
    }
    struct String temp = array[a];
    array[a] = array[b];
    array[b] = temp;
}

// 快排
void quickSort(struct String array[], size_t left, size_t right) {
    if (left >= right) {
        return;
    }
    struct String key = array[left];
    size_t l = left, r = right;
    while (l < r) {
        while (l < r && array[r].reverse >= key.reverse) --r;
        swap(array, l, r);
        while (l < r && array[l].reverse <= key.reverse) ++l;
        swap(array, l, r);
    }
    array[l] = key;
    quickSort(array, left, l - 1);
    quickSort(array, l + 1, right);
}

// 暴力计算
size_t getReverse(const struct String *const string, const size_t length) {
    size_t sum = 0;
    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (string->str[i] > string->str[j]) {
                ++sum;
            }
        }
    }

    return sum;
}

int main() {
    size_t length = 0, count = 0;
    scanf("%zu %zu", &length, &count);
    length;
    struct String *array = (struct String *) malloc(count * sizeof(struct String));
    for (int i = 0; i < count; ++i) {
        array[i].str = (char *) malloc((length + 1) * sizeof(char));
        scanf("%s", array[i].str);
        array[i].reverse = getReverse(array + i, length);
    }

    quickSort(array, 0, count - 1);

    for (int i = 0; i < count; ++i) {
        printf("%s\n", array[i].str);
    }

    return 0;
}
/*
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
*/

/*
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA
*/
