#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
    // 单价
    double price;
    // 总的价值
    double value;
    friend bool operator<(const Node &a, const Node &b) {
        return a.price < b.price;
    }
};

int main() {
    int N;
    double M;
    cin >> M >> N;
	// 设置小数位
    cout << fixed << setprecision(3);
    // 总价值，总价格
    double value, price;
    Node n;
    while (M != -1 || N != -1) {
        // 分数背包问题，无语了
        double result = 0;
        vector<Node> vs;
        while (N--) {
            cin >> value >> price;
            n.value = value;
            n.price = price / value;
            vs.push_back(n);
        }
        sort(vs.begin(), vs.end());
        int idx = 0, size = vs.size();
        while (M > 0 && idx < size) {
            if (M >= vs[idx].value * vs[idx].price) {
                M -= vs[idx].value * vs[idx].price;
                result += vs[idx].value;
            }
            else {
                result += M / vs[idx].price;
                M = 0;
            }

            idx++;
        }

        cout << result << "\n";

        cin >> M >> N;
    }

    return 0;
}