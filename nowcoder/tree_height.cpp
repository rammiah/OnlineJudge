#include <iostream>
#include <vector>
#include <algorithm>

int main(void) {
    int v_count = 0;
    // 输入节点个数
    std::cin >> v_count;
    // 存放高度的数组
    std::vector<int> depth(v_count, 0);
    // 0节点为已知，高度为1
    depth[0] = 1;
    // 存放父子的节点对
    std::vector<std::pair<int, int>> all_pair;
    // 预分配空间
    all_pair.reserve(v_count);

    int parent = 0, child = 0;
    int max_depth = 0;
    // 记录节点的直接子节点数目
    std::vector<int> childrens(v_count, 0);

    // 出题人脑子有毒，说好的二叉树，给我来个多叉的
    for (int i = 0; i < v_count - 1; ++i) {
        std::cin >> parent >> child;
        // 直接子节点数目小于2才进入
        if (childrens[parent] < 2) {
            all_pair.push_back(std::make_pair(parent, child));
            childrens[parent]++;
        }
    }
    // 排序
    std::sort(all_pair.begin(), all_pair.end(),
     [](const std::pair<int, int> &a, const std::pair<int, int> &b)->bool{return a.first < b.first;});
    // 计算最大的高度
    for (const auto &t : all_pair) {
        depth[t.second] = depth[t.first] + 1;
        max_depth = max_depth < depth[t.second] ? depth[t.second] : max_depth;
    }
    // 输出结果
    std::cout << max_depth << std::endl;

    return 0;
}
