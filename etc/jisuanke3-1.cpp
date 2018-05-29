#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int val;
    int s;
    friend bool operator<(const Node &a, const Node &b) {
        return a.s < b.s;
    }
};

Node nodes[100005];

int main() {
    int T;
    scanf("%d", &T);
    Node n;
    while (T--) {
        int cnt;
        scanf("%d", &cnt);
        for (int i = 0; i < cnt; ++i) {
            scanf("%d %d", &nodes[i].s, &nodes[i].val);
        }
        double max = 0;
        sort(nodes, nodes + cnt);
        double temp = 0;
        for (int i = 0; i < cnt - 1; ++i) {
            if (nodes[i].s == nodes[i + 1].s) {
                max = -1;
                break;
            }
            temp = abs(1.0 * (nodes[i].val - nodes[i + 1].val) / (nodes[i].s - nodes[i + 1].s));
            max = max > temp ? max : temp;
        }
        printf("%f\n", max);
    }

    return 0;
}