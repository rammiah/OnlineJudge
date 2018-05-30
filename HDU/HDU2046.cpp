#include <iostream>

using namespace std;

using ull = unsigned long long;
ull nums[55] = {0, 1, 2 };

int main() {
    for (int i = 3; i < 55; ++i) {
        nums[i] = nums[i - 1] + nums[i - 2];
    }
    int num;

    while (cin >> num) {
        cout << nums[num] << "\n";
    }

    return 0;
}