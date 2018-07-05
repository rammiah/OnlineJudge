#define _CRT_SECURE_NO_WARNINGS
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
#define MAXN 505

using namespace std;
using ll = long long;

using namespace std;

struct Record {
    int x, y;
    int type;
    double sceond;
    friend bool operator<(const Record &a, const Record &b) {
        return a.sceond < b.sceond;
    }
};

int result[MAXN][MAXN];
int rooms[MAXN][MAXN];

int main() {
    int m, n, rec_cnt;
    scanf("%d %d %d", &m, &n, &rec_cnt);
    // 开始输入记录，最后排序
    vector<Record> recs;
    Record r;
    int hour, minute;
    for (int i = 0; i < rec_cnt; ++i) {
        scanf("%d %d %d %d:%d:%lf", &r.x, &r.y, &r.type, &hour, &minute, &r.sceond);
        r.sceond += hour * 3600 + minute * 60;
        recs.push_back(r);
    }
    sort(recs.begin(), recs.end());
    // 开始记录房间个数
    int max = 0, now = 0;
    for (auto &rec : recs) {
        // 0进1出
        if (rec.type == 0) {
            if (rooms[rec.x][rec.y] == 0) {
                now++;
            }
            rooms[rec.x][rec.y]++;
            if (now >= max) {
                memcpy(result, rooms, sizeof(result));
                max = now;
            }
        }
        else {
            if (rooms[rec.x][rec.y] == 1) {
                now--;
            }
            rooms[rec.x][rec.y]--;
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%d", result[i][j] > 0 ? 1 : 0);
        }
        printf("\n");
    }

    return 0;
}