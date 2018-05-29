#include <iostream>

const int CNT = 1000005;

int records[CNT];

bool is_good(int num) {
    while (num > 0) {
        if (num % 100 == 62 || num % 10 == 4) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int main() {
    // 打表
    int cnt = 0;
    for (int i = 1; i < CNT; ++i) {
        records[i] = records[i - 1] + 1;
        if (!is_good(i)) {
            records[i]--;
        }
    }
    // std::cout << records[95] - records[1];
    int a = 0, b = 0;
    std::cin >> a >> b;
    while (a != 0 || b != 0) {
        std::cout << records[b] - records[a] + (is_good(a) ? 1 : 0) << "\n";
        std::cin >> a >> b;
    }
    return 0;
}

