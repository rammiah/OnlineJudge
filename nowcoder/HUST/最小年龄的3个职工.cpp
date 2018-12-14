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
#include <queue>

using namespace std;

struct Employ {
    int id;
    string name;
    int age;

    friend bool operator>(const Employ &a, const Employ &b) {
        if (a.age > b.age) {
            return true;
        }
        else if (a.age < b.age) {
            return false;
        }

        if (a.id > b.id) {
            return true;
        }
        else if (a.id < b.id) {
            return false;
        }
        return a.name > b.name;
    }
};

int main() {
    int cnt;

    while (cin >> cnt) {
        priority_queue<Employ, vector<Employ>, greater<Employ>> pq;
        Employ p;
        for (int i = 0; i < cnt; ++i) {
            cin >> p.id >> p.name >> p.age;
            pq.push(p);
        }
        for (int i = 0; i < 3 && !pq.empty(); ++i) {
            p = pq.top();
            pq.pop();
            cout << p.id << " " << p.name << " " << p.age << "\n";
        }
    }
    
    return 0;
}
