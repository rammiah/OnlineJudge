#include <iostream>
#include <set>

using namespace std;

// 无聊之人必有无聊之处
int main() {
    int cnt;
    cin >> cnt;
    set<int> nums;
    int num;
    while (cnt--) {
        cin >> num;
        nums.insert(num);
    }

    cout << nums.size() << "\n";

    return 0;
}
// 梁静茹 - 可惜不是你