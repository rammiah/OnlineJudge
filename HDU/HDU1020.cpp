#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

string compress(const string &str) {
    string result;
    int freq = 0;
    char old_char = str[0];
    int len = str.length();
    for (auto &ch : str) {
        if (ch == old_char) {
            ++freq;
        }
        else {
            if (freq > 1) {
                result.append(to_string(freq));
            }
            result.push_back(old_char);
            old_char = ch;
            freq = 1;
        }
    }
    if (freq > 1) {
        result.append(to_string(freq));
    }
    result.push_back(old_char);
    return result;
}

int main() {
    int cnt;
    string str;
    cin >> cnt;
    while (cnt--) {
        cin >> str;
        cout << compress(str) << "\n";
    }

    return 0;
}
