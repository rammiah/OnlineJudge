#include <cstdio>
#include <set>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int rate[24];
struct Record{
    int day, hour, min;
    Record(int day, int hour, int min):day(day), hour(hour), min(min){}
    friend bool operator<(const Record &a, const Record &b) {
        return a.day * 1440 + a.hour * 60 + a.min < b.day * 1440 + b.hour * 60 + b.min ;
    }

    friend int operator-(const Record &a, const Record &b) {
        return a.day * 1440 + a.hour * 60 + a.min - b.day * 1440 + b.hour * 60 + b.min;
    }
};

struct User{
    string name;
    vector<Record> on;
    vector<Record> off;
    friend bool operator<(const User &a, const User &b) {
        return a.name < b.name;
    }
};

double calcu_cost(const Record &start, const Record &end) {
    // 计算费用啊
    // 判断是否跨天了
    double cost = 0;
    if (start.day == end.day) {
        // 没有跨天
        int hour = start.hour;
        cost += rate[hour] * (60 - start.min);
        ++hour;
        while (hour < end.hour) {
            cost += rate[hour % 24] * 60;
            hour++;
        }
        cost += rate[end.hour] * end.min;
    } else {
        // 跨天了，问题是有可能跨好几天。。。
        int cross_days = end.day - start.day - 1;
        for (int i = 0; i < 24; ++i) {
            cost += rate[i] * 60 * cross_days;
        }
        // 计算只跨一次00:00的费用
        int hour = start.hour - 24;
        cost += rate[(hour + 24) % 24] * (60 - start.min);
        while (hour < end.hour) {
            cost += rate[(hour + 24) % 24] * 60;
            ++hour;
        }
        cost += rate[end.hour] * end.min;
    }
    // 转换为美元
    return cost / 100;
}

int main() {
    // 获取费率
    for (int i = 0; i < 24; ++i) {
        scanf("%d", &rate[i]);
    }
    int cnt;
    scanf("%d", &cnt);
    set<string> users;
    char name[25];
    char on_off[5];
    string s;
    int month, day, hour, min;
    map<string, User>m;

    while (cnt--) {
        scanf("%s %d:%d:%d:%d %s-line", name, &month, &day, &hour, &min, on_off);
        s = name;
        // 未记录此用户
        if (users.find(s) != users.end()) {
            users.insert(s);
        } else {
            if (on_off[1] == 'n') {
                m[s].on.emplace_back(day, hour, min);
            } else {
                m[s].off.emplace_back(day, hour, min);
            }
        }
    }
    // 开始算帐单，一个一个用户的输出
    // 遍历map
    for (auto &u : m) {
        printf("%s %02d\n", u.first.c_str(), month);        
        auto &on = u.second.on;
        auto &off = u.second.off;
        // 要不先把on和off先排序
        sort(on.begin(), on.end());
        sort(off.begin(), off.end());
        double total = 0;
        double once = 0;
        int on_size = on.size(), off_size = off.size();
        int off_idx = 0;
        for (int i = 0; i < on_size; ++i) {
            if (off[off_size - 1] < on[i]) {
                // 不可能, 而且接着的后面的也不能了
                break;
            }
            // 寻找可用的下线时间
            for (; off_idx < off_size; ++off_idx) {
                if (on[i] < off[off_idx]) {
                    // 第一个就是，赶紧计算值并删除记录
                    once = calcu_cost(on[i], off[off_idx]);
                    // 输出并停止迭代
                    // 可能还需要重载一下减号
                    printf("%02d %02d %02d %02d %02d %02d %d $%.2f\n", 
                    on[i].day, on[i].hour, on[i].min, off[off_idx].day,
                     off[off_idx].hour, off[off_idx].min, off[off_idx] - on[i], once);
                    total += once;
                    //
                    break;
                }
            }
        }
        // 输出总数
        printf("Total amount: $%.2f\n", total);
    }


    return 0;
}