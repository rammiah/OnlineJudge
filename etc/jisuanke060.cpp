#include <cstdio>
#include <queue>

using namespace std;

struct Node {
    int price;
    int cnt;
    // 价格低的应该排在前面
    friend bool operator<(const Node &a, const Node &b) {
        return a.price > b.price;
    }
};

int main() {
    // freopen("060.txt", "r", stdin);
    int sum, cnt;
    scanf("%d %d", &sum, &cnt);
    // 默认大顶堆
    priority_queue<Node> all;
    Node n;
    while (cnt--) {
        scanf("%d %d", &n.price, &n.cnt);
        all.push(n);
    }

    int result = 0;
    while (sum > 0) {
        n = all.top();
        all.pop();
        if (sum >= n.cnt) {
            result += n.cnt * n.price;
            sum -= n.cnt;
        } else {
            result += sum * n.price;
            sum = 0;
        }
    }

    printf("%d\n", result);

    return 0;
}
