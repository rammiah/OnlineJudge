#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <math.h>
#include <climits>
#include <cfloat>
#include <iomanip>

const int TEAM_CNT = 16;
using ll = long long;

double rates[TEAM_CNT][TEAM_CNT];
double eights[TEAM_CNT];
double fours[TEAM_CNT];
double twos[TEAM_CNT];
double winner[TEAM_CNT];

std::vector<int> get_four(int id) {
    // 可知会有2个
    // 获取4强对手
    std::vector<int> vs(2);
    if (id < 2) {
        vs[0] = 2;
        vs[1] = 3;
    }
    else if (id < 4) {
        vs[0] = 0;
        vs[1] = 1;
    }
    else if (id < 6) {
        vs[0] = 6;
        vs[1] = 7;
    }
    else if (id < 8) {
        vs[0] = 4;
        vs[1] = 5;
    }
    else if (id < 10) {
        vs[0] = 10;
        vs[1] = 11;
    }
    else if (id < 12) {
        vs[0] = 8;
        vs[1] = 9;
    }
    else if (id < 14) {
        vs[0] = 14;
        vs[1] = 15;
    }
    else {
        vs[0] = 12;
        vs[1] = 13;
    }
    return vs;
}

std::vector<int> get_two(int id) {
    std::vector<int> vs;
    if (id < 4) {
        for (int i = 4; i < 8; ++i) {
            vs.push_back(i);
        }
    }
    else if (id < 8) {
        for (int i = 0; i < 4; ++i) {
            vs.push_back(i);
        }
    }
    else if (id < 12) {
        for (int i = 12; i < 16; ++i) {
            vs.push_back(i);
        }
    }
    else {
        for (int i = 8; i < 12; ++i) {
            vs.push_back(i);
        }
    }
    return vs;
}

std::vector<int> get_one(int id) {
    std::vector<int> vs;
    if (id < 8){
        for (int i = 8; i < 16; ++i) {
            vs.push_back(i);
        }
    }
    else {
        for (int i = 0; i < 8; i++) {
            vs.push_back(i);
        }
    }
    return vs;
}
int main() {
    //freopen("D:/GitHub/OnlineJudge/Leetcode/data.txt", "r", stdin);
    // 输入数据
    for (int i = 0; i < TEAM_CNT; ++i) {
        for (int j = 0; j < TEAM_CNT; ++j) {
            std::cin >> rates[i][j];
        }
    }
    // 可知队伍都进入了16强
    // 计算进入8强的概率
    for (int i = 0; i < TEAM_CNT; ++i) {
        if (i & 1) {
            eights[i] = rates[i][i - 1];
        }
        else {
            eights[i] = rates[i][i + 1];
        }
    }
    // 计算进入4强概率
    // 手写完会把我累死的
    for (int i = 0; i < TEAM_CNT; ++i) {
        fours[i] = 0;
        for (auto &id : get_four(i)) {
            fours[i] += eights[i] * eights[id] * rates[i][id];
        }
    }
    // 进入二强概率
    for (int i = 0; i < TEAM_CNT; ++i) {
        twos[i] = 0;
        for (auto &id : get_two(i)) {
            twos[i] += fours[i] * fours[id] * rates[i][id];
        }
    }
    // 获得冠军概率
    for (int i = 0; i < TEAM_CNT; ++i) {
        winner[i] = 0;
        for (auto &id : get_one(i)) {
            winner[i] += twos[i] * twos[id] * rates[i][id];
        }
    }
    double sum = 0;
    for (int i = 0; i < TEAM_CNT - 1; ++i) {
        std::cout << std::fixed << std::setprecision(10) << std::setw(10) << winner[i] << " ";
        sum += winner[i];
    }
    sum += winner[TEAM_CNT - 1];
    std::cout << std::fixed << std::setprecision(10) << winner[TEAM_CNT - 1] << "\n";
    // std::cout << sum << "\n";

    return 0;
}
