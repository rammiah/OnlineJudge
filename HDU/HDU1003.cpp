#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int starts[100005] = { 0, };
int nums[100005] = { 0, };

int main() {
    int cases;
    int num_cnt;
    int max_end, max_val;
    cin >> cases;
    for (int i = 1; i <= cases; ++i) {
        memset(starts, 0, sizeof(starts));
        cin >> num_cnt;
        for (int j = 0; j < num_cnt; ++j) {
            cin >> nums[j];
            if (j == 0) {
                max_val = nums[j];
                starts[j] = 1;
                max_end = 1;
            }
            else if (nums[j - 1] >= 0) {
                nums[j] += nums[j - 1];
                starts[j] = starts[j - 1];
            }
            else {
                starts[j] = j + 1;
            }
            if (max_val < nums[j]) {
                max_end = j + 1;
                max_val = nums[j];
            }
        }

        cout << "Case " << i << ":\n";
        cout << max_val << " " << starts[max_end - 1] << " " << max_end << (i == cases ? "\n" : "\n\n");
    }

    return 0;
}
