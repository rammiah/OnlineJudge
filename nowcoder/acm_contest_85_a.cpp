#define _USE_MATH_DEFINES
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>

using ull = unsigned long long;
using ll = long long;
using uint = unsigned int;

int main() {
    // 获取自然底数e的值
    const double e = M_E;
    int cnt = 0;
    scanf("%d", &cnt);
    while (cnt--) {
        int alpha, beta, gamma;
        scanf("%d %d %d", &alpha, &beta, &gamma);
        double u = 0;
        for (int i = 0; i < alpha; ++i) {
            u *= e;
        }

        printf("%.*f\n", gamma, u * beta);
    }
    
    return 0;
}