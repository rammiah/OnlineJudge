#include <iostream>
#include <string>


using namespace std;

using ull = unsigned long long;

int main() {
    ull num;
    while (cin >> num) {
        int cnt = 0;
        while (num > 0) {
            cnt += num & 1;
            num >>= 1;
        }
        cout << cnt << "\n";
    }

    return 0;
}
