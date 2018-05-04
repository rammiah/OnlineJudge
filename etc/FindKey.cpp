#include <iostream>
using namespace std;

struct Toy{
    int direction;
    string name;
    int index;
}toys[100000];


int main() {
    int toyCount = 0;
    int orderCount = 0;
    cin >> toyCount >> orderCount;
    for (int i = 0; i < toyCount; ++i) {
        cin >> toys[i].direction >> toys[i].name;
        toys[i].index = i;
    }
    int resultIndex = 0;
    int direction = 0, distance = 0;
    for (int i = 0; i < orderCount; ++i) {
        cin >> direction >> distance;
        // 0为向圈内，向左数，即index要减去distance
        resultIndex += (direction^toys[resultIndex].direction) == 1 ? distance : -distance;
        while (resultIndex < 0) resultIndex += toyCount;
        resultIndex %= toyCount;
    }

    cout << toys[resultIndex].name << endl;

    return 0;
}
