#include <iostream>

using namespace std;

int nums[100] = { 0, 1, 1 };

int main() {
    int A, B;
    int n;
    cin >> A >> B >> n;
    // 循环节，学习了
    while (A != 0 || B != 0 || n != 0) {
        for (int i = 3; i <= 49; ++i) {
            nums[i] = (A * nums[i - 1] + B * nums[i - 2]) % 7;
        }
        cout << nums[n % 49] << "\n"; 
        cin >> A >> B >> n;
    }

    return 0;
}