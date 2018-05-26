#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;


int main() {
    int a;
    cin >> a;
    vector<int> as(a);
    for (auto & num : as) {
        cin >> num;
    }
    int b;
    cin >> b;
    vector<int> bs(b);
    for (auto &num : bs) {
        cin >> num;
    }
    int min = INT_MAX;
    for (int i = 0; i < b - a; ++i) {
        int now = 0;
        for (int j = 0; j < a; ++j) {
            now += (as[j] - bs[i + j]) * (as[j] - bs[i + j]);
        }
        min = std::min(now, min);
    }

    cout << min << "\n";

    return 0;
}

