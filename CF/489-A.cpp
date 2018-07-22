#include <iostream>
#include <set>

using namespace std;

int main() {
    int cnt, a;
    cin >> cnt;
    set<int> nums;
    while (cnt--) {
        cin >> a;
        if (a != 0) {
            nums.insert(a);
        }
    }

    cout << nums.size() << "\n";

    return 0;
}