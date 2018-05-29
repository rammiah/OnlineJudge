#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int area;
    friend bool operator<(const Person &p1, const Person &p2) {
        return p1.area < p2.area;
    }
};

int main() {
    int cnt = 0;
    while ((cin >> cnt, cnt) != -1) {
        vector<Person> ps;
        Person p;
        int cnt_cp = cnt;
        int a, b, c;        
        string name;
        while (cnt_cp--) {
            cin >> a >> b >> c >> name;
            p.area = a * b * c;
            p.name = name;
            ps.push_back(p);
        }
        sort(ps.begin(), ps.end());
        cout << ps.back().name << " took clay from " << ps.front().name << ".\n";
    }

    return 0;
}