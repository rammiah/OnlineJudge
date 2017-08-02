#include <iostream>
bool IsPrime(const int N){
    if (N < 2)return false;
    if (N == 2)return true;
    for (int i = 3; i <= N / 2; ++i){
        if (N % i == 0)return false;
    }
    return true;
}

int Reverse(const int N, const int radix){
    int result = 0;
    int t = N;
    while (t > 0){
        result = result * radix + t % radix;
        t /= radix;
    }
    return result;
}

int main(void)
{
    int t = 0;
    int radix = 0;
    while ((std::cin >> t, t) > 0){
        std::cin >> radix;
        if (IsPrime(t) && IsPrime(Reverse(t, radix))){
            std::cout << "Yes" << std::endl;
        }
        else{
            std::cout << "No" << std::endl;
        }
    }
    return 0;
}
