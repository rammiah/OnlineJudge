#include <iostream>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    int sum;
    while (cnt != 0) {
        sum = 0;
        int last = 0, to;
        // up 6 down 4, 5
        while (cnt--) {
            cin >> to;
            if (to > last) {
                sum += 6 * (to - last) + 5;
            } else if (to < last) {
                sum += 4 * (last - to) + 5;
            } else {
                sum += 5;
            }
            last = to;
        }

        cout << sum << "\n";

        cin >> cnt;
    }

    return 0;
}