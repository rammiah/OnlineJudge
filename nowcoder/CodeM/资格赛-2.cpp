#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <cfloat>

using ll = long long;

int main() {
    ll sum_cnt, m, kinds;
    std::cin >> sum_cnt >> m >> kinds;
    ll t = sum_cnt - m;

    ll result = 0;
    ll max_value, temp_value;
    ll m_happy, t_happy;
    for (int i = 0; i < kinds; ++i) {
        std::cin >> m_happy >> t_happy;
        temp_value = m_happy * m + t_happy * t;
        if (i == 0 || temp_value >= max_value) {
            max_value = temp_value;
            result = i;
        }
    }

    for (int i = 0; i < kinds - 1; ++i) {
        std::cout << (i == result ? sum_cnt : 0) << " ";
    }
    std::cout << (kinds - 1 == result ? sum_cnt : 0) << "\n";

    return 0;
}
