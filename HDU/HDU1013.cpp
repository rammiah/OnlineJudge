#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

using namespace std;

string get_root(string &num) {
    if (num.length() == 1) {
        return num;
    }
    int carry = 0;
    string result;
    for (auto &ch : num) {
        carry += ch - '0';
        if (carry >= 10) {
            result.push_back(carry % 10 + '0');
            carry /= 10;
        }
    }
    if (carry > 0) {
        result.push_back(carry + '0');
    }

    return get_root(result);
}

int main() {
    string num;
    cin >> num;
    while (num != "0") {
        cout << get_root(num) << "\n";
        cin >> num;
    }

    return 0;
}