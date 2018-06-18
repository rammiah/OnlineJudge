using ll = long long;

struct Node {
	int position;
	int speed;
	double use_time;
	friend bool operator<(const Node &a, const Node &b) {
		// 怎么排序
		return a.position >= b.position;
	}


	friend bool operator==(const Node &a, const Node &b) {
		return a.position >= b.position && a.use_time >= b.use_time;
	}
};

class Solution {
public:
	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		if (position.size() == 0) {
			return 0;
		}
		// 直接模拟需要从前向后模拟吧，如果一辆车可以
		int size = position.size();
		vector<Node> nodes;
		Node n;
		for (int i = 0; i < size; ++i) {
			n.position = position[i];
			n.speed = speed[i];
			n.use_time = 1.0 * (target - n.position) / n.speed;
			nodes.push_back(n);
		}
		sort(nodes.begin(), nodes.end());
		// 开始判断能否追上
		int result = 1;
		Node old = nodes[0];
		for (int i = 1; i < size; ++i) {
			if (!(old == nodes[i])) {
				old = nodes[i];
				++result;
			}
		}

		return result;
	}
};