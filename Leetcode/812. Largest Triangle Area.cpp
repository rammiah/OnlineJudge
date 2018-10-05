struct MyPoint {
    int x;
    int y;
};

double distance(MyPoint &a, MyPoint &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double calcu_area(MyPoint &a, MyPoint &b, MyPoint &c) {
    double x = distance(a, b), y = distance(a, c), z = distance(b, c);
    // 计算面积
    double s = (x + y + z) / 2;
    return sqrt(s * (s - x) * (s - y) * (s - z));
}

class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        // 直接暴力计算也是可以的，测试数据还是比较少的，问题是如何三个点计算面积
        // 使用海伦公式
        // 首先转换所有点
        vector<MyPoint> ps;
        MyPoint p;
        for (auto &v : points) {
            p.x = v[0];
            p.y = v[1];
            ps.push_back(p);
        }
        // 开始三层遍历
        double max_area = 0;
        for (int i = 0; i < ps.size(); ++i) {
            for (int j = i + 1; j < ps.size(); ++j) {
                for (int k = j + 1; k < ps.size(); ++k) {
                    max_area = max(max_area, calcu_area(ps[i], ps[j], ps[k]));
                }
            }
        }

        return max_area;
    }
};
