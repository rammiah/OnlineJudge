#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <queue>

using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    int year, day;
    int month;
    while (~scanf("%d %d", &year, &day)) {
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
            months[1] = 29;
        }
        else {
            months[1] = 28;
        }
        month = 0;
        while (day > months[month]) {
            day -= months[month];
            month++;
        }
        printf("%4d-%02d-%02d\n", year, month + 1, day);
    }

    return 0;
}
