#include <cstdio>
#include <cstdio>

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? (-a) : (a))
// 10亿个数
#define _MAX 1000000000

unsigned short pixels[_MAX];

unsigned short get_diff(const int &width, const int &index, const int &sum) {
    static int up = 0, down = 0, left = 0, right = 0;
    static int upleft = 0, upright = 0, downleft = 0, downright = 0;
    up = index - width;
    up = up < 0 ? index : up;
    upleft = up % width == 0 || up == index ? index : up - 1;
    upright = (up + 1) % width == 0 || up == index ? index : up + 1;
    down = index + width;
    down = down >= sum ? index : down;
    downleft = down % width == 0 || down == index ? index : down - 1;
    downright = (down + 1) % width == 0 || down == index ? index : down + 1;
    
    left = index % width == 0 ? index : index - 1;
    right = (index + 1) % width == 0 ? index : index + 1;

    int a = pixels[up], b = pixels[down], c = pixels[left], d = pixels[right];
    int e = pixels[upleft], f = pixels[upright], g = pixels[downleft], h = pixels[downright];
    int _this = pixels[index];

    int max = 0;
    max = MAX(ABS(a - _this), max);
    max = MAX(ABS(b - _this), max);
    max = MAX(ABS(c - _this), max);
    max = MAX(ABS(d - _this), max);
    max = MAX(ABS(e - _this), max);
    max = MAX(ABS(f - _this), max);
    max = MAX(ABS(g - _this), max);
    max = MAX(ABS(h - _this), max);
    return (unsigned short)max;
}

int main() {
    int width = 0;
    while (scanf("%d", &width), width != 0) {
        unsigned short num = 0;
        int cnt = 0;
        int pix_cnt = 0;
        int sum = 0;

        while (scanf("%hu %d", &num, &cnt), num != 0 && cnt != 0) {
            sum += cnt;
            for (int i = 0; i < cnt; ++i) {
                pixels[pix_cnt++] = num;
            }
        }


        cnt = 1;
        int cur_diff = get_diff(width, 0, sum), temp_diff = 0;
        printf("%d\n", width); 
        for (int i = 1; i < sum; ++i) {
            temp_diff = get_diff(width, i, sum);    
            if (temp_diff == cur_diff) {
                cnt++;
            } else {
                printf("%hu %d\n", cur_diff, cnt);
                cnt = 1;
                cur_diff = temp_diff;
            }
        }
        printf("%hu %d\n", cur_diff, cnt);
        printf("0 0\n");
    }
    printf("0\n");

    return 0;
}

/*
 Sample Input

7
15 4
100 15
25 2
175 2
25 5
175 2
25 5
0 0
10
35 500000000
200 500000000
0 0
3
255 1
10 1
255 2
10 1
255 2
10 1
255 1
0 0
0
Sample Output

7
85 5
0 2
85 5
75 10
150 2
75 3
0 2
150 2
0 4
0 0
10
0 499999990
165 20
0 499999990
0 0
3
245 9
0 0
0
Hint
 
 */
