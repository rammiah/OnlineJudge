#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int get_radix(char ch) {
    int result;
    switch (ch) {
    case '0':
    case 'd':
        result = 10;
        break;
    default:
        result = ch - '0';
        break;
    }

    return result;
}

void removez(string &str) {
    while (str[0] == '0' && str.length() > 1) {
        str.erase(str.begin());
    }
}

int main() {
    string radix_str;
    string numa_str, numb_str;
    // 前导0我是很烦的
    cin >> radix_str >> numa_str >> numb_str;
    removez(numa_str);
    removez(numb_str);
    std::reverse(radix_str.begin(), radix_str.end());
    std::reverse(numa_str.begin(), numa_str.end());
    std::reverse(numb_str.begin(), numb_str.end());
    string result;
    int idxa = 0, idxb = 0, idxr = 0;
    int radix = 10;
    int carry = 0;
    string rep = " ";
    while (idxa < numa_str.length() || idxb < numb_str.length() || carry > 0) {
        radix = 10;
        if (idxr < radix_str.length()) {
            radix = get_radix(radix_str[idxr++]);
        }
        int a = idxa < numa_str.length() ? numa_str[idxa++] - '0' : 0;
        int b = idxb < numb_str.length() ? numb_str[idxb++] - '0' : 0;
        carry += a + b;
        result.push_back(carry % radix + '0');
        carry /= radix;
        carry = !!carry;
    }
    
    std::reverse(result.begin(), result.end());;
    cout << result << "\n";
    return 0;
}

