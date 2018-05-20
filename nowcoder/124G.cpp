#include <iostream>
#include <queue>

using namespace std;

using ull = unsigned long long;

struct Node {
    int val;

    friend bool operator<(const Node &a, const Node &b) {
        return a.val > b.val;
    }
};

int main() {
    int cnt;

    while (cin >> cnt) {
        priority_queue<Node> q;
        Node n;
        while (cnt--) {
            cin >> n.val;
            q.push(n);
        }

        ull result = 0;
        while (q.size() > 1) {
            int a = q.top().val;
            q.pop();
            int b = q.top().val;
            q.pop();
            n.val = a + b;
            result += n.val;
            q.push(n);
        }
        cout << result << "\n";
    }


    return 0;
}
