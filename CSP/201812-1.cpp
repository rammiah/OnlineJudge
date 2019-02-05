#include <iostream>
#include <algorithm>
#include <vector>

enum Light {
    None, Red, Yellow, Green
};

int main() {
    int r, y, g;
    // 三个灯的时间
    std::cin >> r >> y >> g;
    int n;
    // k和t
    int k, t;
    // 数据数目
    std::cin >> n;
    // 记录最终结果
    int res = 0;
    while (n--) {
        std::cin >> k >> t;
        // switch决定下一步
        switch (k) {
            case None:
                res += t;
                break;
            case Red:
                res += t;
                break;
            case Yellow:
                res += t + r;
                break;
            case Green:
                break;
            default:
                break;
        }
    }

    std::cout << res << std::endl;


    return 0;
}

