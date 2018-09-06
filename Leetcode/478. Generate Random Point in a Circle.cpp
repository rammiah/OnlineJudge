// 在给定的圆中生成随机点，保证在圆中均匀分布，考察概率论的知识
// 直接考虑圆的是比较复杂的，由概率论s知识知道二维变量中的正方形的概率是均匀分布的，直接生成正方形中的一个点，检测是否在圆中，不在再重新生成
class Solution {
	double radius;
	double x_center, y_center;
public:
	Solution(double radius, double x_center, double y_center)
		:radius(radius), x_center(x_center), y_center(y_center) { }

	vector<double> randPoint() {
		double x = rand() * radius / RAND_MAX * 2 - radius;
		double y = rand() * radius / RAND_MAX * 2 - radius;
		while (x * x + y * y > radius * radius) {
			x = rand() * radius / RAND_MAX * 2 - radius;
			y = rand() * radius / RAND_MAX * 2 - radius;
		}
		return vector<double> {x + x_center, y + y_center};
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
