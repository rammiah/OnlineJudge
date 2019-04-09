class Solution {
	struct Point {
		int x;
		int y;
		int dist;
		Point(int x = 0, int y = 0):x(x), y(y) {
			dist = x * x + y * y;
		}
	};

	struct Comp {
		bool operator()(const Point& a, const Point& b) {
			return a.dist < b.dist;
		}
	};

public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		std::priority_queue<Point, std::vector<Point>, Comp> q;
		Comp comp;
		for (auto& p : points) {
			if (q.size() < K) {
				q.emplace(p[0], p[1]);

			}
			else if (comp(Point(p[0], p[1]), q.top())) {
				q.pop();
				q.emplace(p[0], p[1]);
			}
		}
		std::vector<std::vector<int>> res;
		while (!q.empty()) {
			auto& p = q.top();
			res.push_back(std::vector<int>{p.x, p.y});
			q.pop();
		}
		return res;
	}
};