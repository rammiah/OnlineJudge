#include <cstdio>

using namespace std;

int nums[100005];

int main() {
	int num_cnt, ops;
	scanf("%d %d", &num_cnt, &ops);
	for (int i = 1; i <= num_cnt; ++i) {
		scanf("%d", &nums[i]);
	}
	// 开始操作
	int op;
	int idx, value, all_add = 0;
	for (int i = 0; i < ops; ++i) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d %d", &idx, &value);
			nums[idx] = value - all_add;
		} else if (op == 2) {
			scanf("%d", &value);
			all_add += value;
		} else {
			// 输出
			scanf("%d", &idx);
			printf("%d\n", nums[idx] + all_add);
		}
	}
	return 0;
}