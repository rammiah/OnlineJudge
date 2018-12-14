#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>

using namespace std;

int main() {
    string str;
    int str_cnt = 0;
    int ch_cnt = 0;
    map<char, int> ch_freq;
    while (cin >> str) {
        str_cnt++;
        ch_cnt += str.length();
        for (auto &ch : str) {
            ch_freq[tolower(ch)]++;
        }
    }
    cout << ch_cnt << "\n" << str_cnt << "\n";
    vector<char> cs;
    int freq = 0;
    for (auto &pair : ch_freq) {
        if (pair.second > freq) {
            cs.clear();
            cs.push_back(pair.first);
            freq = pair.second;
        }
        else if (pair.second == freq) {
            cs.push_back(pair.first);
        }
    }
    for (auto &ch : cs) {
        cout << ch << " ";
    }
    cout << "\n";
    cout << freq << "\n";
    
    
    return 0;
}