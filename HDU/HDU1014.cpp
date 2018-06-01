#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <set>

using namespace std;

int main() {
    int mod, seed, step;
    while (scanf("%d %d", &step, &mod) != EOF) {
        set<int> nums;
        seed = 0;
        while (nums.count(seed) == 0) {
            nums.insert(seed);
            seed = (seed + step) % mod;
        }
        printf("%10d%10d    %s\n\n", step, mod, (nums.size() == mod ? "Good Choice" : "Bad Choice"));
    }

    return 0;
}