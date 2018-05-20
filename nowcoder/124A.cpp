#include <iostream>
#include <string>


using  namespace std;

string trans(string code) {
    int num = stoi(code);
    // translate code to char
    string res = "aaa";
    res[2] += num % 26;
    num /= 26;
    res[1] += num % 26;
    num /= 26;
    res[0] += num;

    return res;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        int cnt;
        cin >> cnt;
        cnt /= 5;
        string str;
        cin >> str;
        for (int i = 0; i < cnt; ++i) {
            cout << trans(str.substr(i * 5, 5));
        }
        cout << "\n";
    }


    return 0;
}
