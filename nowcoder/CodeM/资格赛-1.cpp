#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int buy_cnt, dis_cnt;
    scanf("%d %d", &buy_cnt, &dis_cnt);
    // 记录总价和第一种方案的总价
    double first_sum = 0, sum = 0;
    double price;
    int can_dis;
    for (int i = 0; i < buy_cnt; ++i) {
        scanf("%lf %d", &price, &can_dis);
        first_sum += price * (can_dis ? 0.8 : 1);
        sum += price;
    }
    // 记录满减优惠的价格
    double second_sum = sum;
    double full, dis;
    for (int i = 0; i < dis_cnt; ++i) {
        scanf("%lf %lf", &full, &dis);
        if (sum >= full) {
            second_sum = std::min(second_sum, sum - dis);
        }
    }
    // 输出较小价格
    printf("%.02f\n", min(first_sum, second_sum));

    return 0;
}