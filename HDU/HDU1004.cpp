#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int cnt;
    cin >> cnt;
    while (cnt != 0) {
        map<string, int> m;
        string str;
        string most;
        int max = 0;
        for (int i = 0; i < cnt; ++i) {
            cin >> str;
            ++m[str];
            if (m[str] > max) {
                max = m[str];
                most = str;
            }
        }
        cout << most << "\n";

        cin >> cnt;
    }

    return 0;
}
