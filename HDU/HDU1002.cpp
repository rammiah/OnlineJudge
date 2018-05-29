#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

void removez(string &s) {
    while (s.length() > 1 && s[0] == '0') {
        s.erase(s.begin());
    }
}

string get_sum(string &a, string &b) {
    string result;
    int carry = 0;
    // 去除前置0
    removez(a);
    removez(b);
    int numa, numb;
    int idxa = a.length() - 1, idxb = b.length() - 1;
    while (idxa >= 0 || idxb >= 0 || carry > 0) {
        numa = idxa >= 0 ? a[idxa--] - '0' : 0;
        numb = idxb >= 0 ? b[idxb--] - '0' : 0;
        carry += numa + numb;
        result.push_back('0' + carry % 10);
        carry /= 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a, b;
    int cnt;
    cin >> cnt;
    for (int i = 1; i <= cnt; ++i) {
        cin >> a >> b;
        cout << "Case " << i << ":\n";
        cout << a << " + " << b << " = " << get_sum(a, b) << (i == cnt ? "\n" : "\n\n");
    }

    return 0;
}
