#include <iostream>
#include <algorithm>
#include <vector>

enum Light {
    None, Red, Yellow, Green
};

int r, y, g;

// 某个灯为起始
long long wait_time(Light light, int left, long long time) {
    long long res = 0;
    // g y r
    // switch决定下一步
    switch (light) {
        case None:
            return left;
        case Red:
            time += g + y + r - left;
            break;
        case Yellow:
            time += g + y - left;
            break;
        case Green:
            time += g - left;
            break;
        default:
            break;
    }
    time %= (g + y + r);
    if (time >= 0 && time < g) {
        return 0;
    }
    return g + y + r - time;
}

int main() {
    // 三个灯的时间
    std::cin >> r >> y >> g;
    int n;
    // k和t
    int k, t;
    // 数据数目
    std::cin >> n;
    // 记录最终结果
    long long res = 0;
    while (n--) {
        std::cin >> k >> t;
        res += wait_time(Light(k), t, res);
    }

    std::cout << res << std::endl;


    return 0;
}

