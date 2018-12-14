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

struct Student {
    string name;
    int age;
    int score;

    friend bool operator<(const Student &a, const Student &b) {
        if (a.score < b.score) {
            return true;
        }
        else if (a.score > b.score) {
            return false;
        }
        if (a.name < b.name) {
            return true;
        }
        else if (a.name > b.name) {
            return false;
        }
        return a.age < b.age;
    }
};


int main() {
    vector<Student> ss;
    int cnt;
    Student s;
    while (cin >> cnt) {
        ss.clear();
        for (int i = 0; i < cnt; ++i) {
            cin >> s.name >> s.age >> s.score;
            ss.push_back(s);
        }
        sort(ss.begin(), ss.end());
        for (int i = 0; i < cnt; ++i) {
            cout << ss[i].name << " " << ss[i].age << " " << ss[i].score << "\n";
        }
    }
    
    
    return 0;
}
