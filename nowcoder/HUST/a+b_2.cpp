#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int str_to_num(string &str) {
    int num = 0;
    int flag = 1;
    int idx = 0;
    if (str[idx] == '-') {
        flag = -1;
        ++idx;
    }
    while (idx < str.length()) {
        if (isdigit(str[idx])) {
            num = num * 10 + str[idx] - '0';
        }
        idx++;
    }
    return num * flag;
}


int main() {
    string strA, strB;
    while (cin >> strA >> strB) {
        cout << str_to_num(strA) + str_to_num(strB) << "\n";
    }
    
    return 0;
}
