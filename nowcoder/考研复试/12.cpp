#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;


int main() {
    int N, t;
    int maxv = INT_MIN, minv = INT_MAX;
    while (cin >> N) {
        maxv = INT_MIN;
        minv = INT_MAX;
        while (N--) {
            cin >> t;
            maxv = max(maxv, t);
            minv = min(minv, t);
        }
        cout << maxv << " " << minv << "\n";
    }

    return 0;
}