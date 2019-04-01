class Solution {
	struct Point {
		int x;
		int y;
		int dist;
		Point(int x = 0, int y = 0):x(x), y(y) {
			dist = x * x + y * y;
		}
	};

	struct comp {
		bool operator()(const Point& a, const Point& b) {
			return a.dist > b.dist;
		}
	};

public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		std::priority_queue<Point, std::vector<Point>, comp> q;
		for (auto& p : points) {
			q.emplace(p[0], p[1]);
		}
		std::vector<std::vector<int>> res;
		while (K > 0) {
			--K;
			auto& p = q.top();
			res.push_back(std::vector<int>{p.x, p.y});
			q.pop();
		}
		return res;
	}
};