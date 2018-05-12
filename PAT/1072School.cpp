#include <cstdio>
#include <unordered_set>
#include <vector>
using namespace std;
int main() {
    unordered_set<int> things;
    int people_cnt, thing_cnt;
    scanf("%d %d", &people_cnt, &thing_cnt);
    int thing;
    while (thing_cnt--) {
        scanf("%d", &thing);
        things.insert(thing);
    }

    int people_sum = 0, thing_sum = 0;
    char name[20];
    auto end = things.end();
    while (people_cnt--) {
        vector<int> bad;
        scanf("%s %d", name, &thing_cnt);
        while (thing_cnt--) {
            scanf("%d", &thing);
            if (things.find(thing) != end) {
                bad.push_back(thing);
            }
        }
        if (bad.size() > 0) {
            printf("%s:", name);
            for (auto &t : bad) {
                // 坑爹啊，都没说需要输出够4位
                printf(" %04d", t);
            }
            printf("\n");
            ++people_sum;
            thing_sum += bad.size();
        }
    }
    printf("%d %d\n", people_sum, thing_sum);

    return 0;
}