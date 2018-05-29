#include <iostream>

using namespace std;

int nums[100];

// 我为什么要写真么无聊的题
int main() {
    int cnt, to_del;
    cin >> cnt;
    for (int i = 0; i < cnt; ++i) {
        cin >> nums[i];
    }
    cin >> to_del;
    int result = 0;
    for (int i = 0; i < cnt; ++i) {
        result += nums[i] != to_del ? 1 : 0;
    }
    cout << result << "\n";

    return 0;
}