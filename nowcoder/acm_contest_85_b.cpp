#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
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
    const double e = M_E;
    int cnt = 0;
    scanf("%d", &cnt);
    int delta, epsilon, miu;
    double wtf = 0;
    while (cnt--) {
        scanf("%d %d %d", &delta, &epsilon, &miu);
        printf("%.*f\n", miu, std::pow(delta, e) / epsilon);
    }
    
    return 0;
}