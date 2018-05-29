#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using ll = long long;

int main() {
    // 权重
    double weights[10];
    ll p_cnt, rounds, needs;
    double max;
    std::cin >> p_cnt >> rounds >> needs >> max;
    // 输入每场比赛的权重
    for (int i = 0; i < rounds; ++i) {
        std::cin >> weights[i];
    }
    // 1是出线，2是不出线，3是不确定
    ll score;
    // 记录丢失的人的id和对应的场次
    int lost_id, lost_idx;
    std::vector<std::vector<double>> scores(p_cnt, std::vector<double>(rounds, 0));
    // 记录加权后每场最大值
    std::vector<double> max_scores(rounds, 0);
    for (int i = 0; i < p_cnt; ++i) {
        for (int j = 0; j < rounds; ++j) {
            std::cin >> score;
            if (score == -1) {
                lost_id = i;
                lost_idx = j;
            }
            // 直接记录加权后
            scores[i][j] = score * weights[j];
            max_scores[j] = std::max(max_scores[j], scores[i][j]);
        }
    }
    // 假定第lost_idx场lost_id的分数为0，计算每个人出线可能
    std::vector<int> min_poss(p_cnt, 0);
    std::vector<int> max_poss(p_cnt, 0);
    // 缺失场置为0
    scores[lost_id][lost_idx] = 0;
    // 计算所有人成绩放入map，同分id放入同一个vector
    std::map<double, std::vector<int>> m;
    // 最终成绩
    std::vector<double> final_score(p_cnt, 0);
    for (int i = 0; i < rounds; ++i) {
        if (max_scores[i] > 0) {
            for (int j = 0; j < p_cnt; ++j) {
                final_score[j] += scores[j][i] / max_scores[i];
            }
        }
    }
    // 总分放入map
    m.clear();
    // 以分数为键放入map
    for (int i = 0; i < p_cnt; ++i) {
        m[final_score[i]].push_back(i);
    }
    ll t_needs = needs;
    auto rit = m.rbegin(), end = m.rend();
    while (rit != end) {
        if (t_needs > 0) {
            if (rit->second.size() <= t_needs) {
                for (auto &id : rit->second) {
                    // 一定出线
                    min_poss[id] = 1;
                }
                t_needs -= rit->second.size();
            }
            else {
                // 需要系统随机选人，都是可能出线
                for (auto &id : rit->second) {
                    min_poss[id] = 3;
                }
                t_needs = 0;
            }
        }
        else {
            // 直接置为2，不可能出线
            for (auto &id : rit->second) {
                min_poss[id] = 2;
            }
        }
        ++rit;
    }
    // 缺失分数设置为最大
    scores[lost_id][lost_idx] = max * weights[lost_idx];
    max_scores[lost_idx] = std::max(scores[lost_id][lost_idx], max_scores[lost_idx]);
    // 清零
    std::fill(final_score.begin(), final_score.end(), 0);
    for (int i = 0; i < rounds; ++i) {
        if (max_scores[i] > 0) {
            for (int j = 0; j < p_cnt; ++j) {
                final_score[j] += scores[j][i] / max_scores[i];
            }
        }
    }
    // 总分放入map
    m.clear();
    for (int i = 0; i < p_cnt; ++i) {
        m[final_score[i]].push_back(i);
    }
    t_needs = needs;
    rit = m.rbegin();
    end = m.rend();
    while (rit != end) {
        if (t_needs > 0) {
            if (rit->second.size() <= t_needs) {
                for (auto &id : rit->second) {
                    max_poss[id] = 1;
                }
                t_needs -= rit->second.size();
            }
            else {
                for (auto &id : rit->second) {
                    max_poss[id] = 3;
                }
                t_needs = 0;
            }
        }
        else {
            for (auto &id : rit->second) {
                max_poss[id] = 2;
            }
        }
        ++rit;
    }
    for (int i = 0; i < p_cnt; ++i) {
        // 两次中结果相同的直接输出，不同的就是未知了
        std::cout << (max_poss[i] == min_poss[i] ? min_poss[i] : 3) << "\n";
    }

    return 0;
}
