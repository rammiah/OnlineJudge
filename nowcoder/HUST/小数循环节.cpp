#include <map>
#include <string>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (a >= b) {
        cout << a / b;
        // 变成余数
        a %= b;
    }
    else {
        cout << "0";
    }
    string decimal;
    if (a > 0) {
        // 此时会产生小数部分
        cout << ".";
        // 记录余数上次出现的地方
        // 注意：如果余数出现了0说明可以除尽，没有循环节
        map<int, int> indexs;
        int index = 0;
        bool have = false;
        while (a > 0) {
            if (indexs.count(a)) {
                // 循环节结束
                have = true;
                break;
            }
            else {
                indexs[a] = index;
                decimal.push_back(a * 10 / b + '0');
                a = a * 10 % b;
            }
            index++;
        }
        if (have) {
            cout << decimal.substr(0, indexs[a]) << "(" << decimal.substr(indexs[a]) << ")\n";
        }
        else {
            cout << decimal << "\n";
        }
    }
    
    return 0;
}