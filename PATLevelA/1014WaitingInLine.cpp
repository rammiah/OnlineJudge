#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
unsigned windows = 0; // 窗口个数
unsigned capicity = 0; // 容纳人数
std::queue<int>* peo = new std::queue<int>[20]; // 先进先出队列
int wins[20]; // 窗口的时间
struct People { // 人结构体
	int use; // 花费时间
	int start; // 开始时间
	int end; // 结束时间
};
void Refresh() {
	int min = 0; // 找出最小的剩余时间
	for (size_t i = 1; i < windows; i++) {
		if (peo[i].front() < peo[min].front())min = i;
	}
	for (size_t i = 0; i < windows; i++) {
		peo[i].front() -= peo[min].front(); // 将时间往后调最短时间
		if (peo[i].front() == 0) peo[i].pop(); // 由于有可能空出多个，都pop
	}
}
int Insert(const int length) {
	int min = 0; // 找出空人最多的窗口
	for (size_t i = 1; i < windows; i++) {
		if (peo[i].size() < peo[min].size())min = i;
	}
	if (peo[min].size() < capicity) { // 如果找出的窗口有空位
		peo[min].push(length);
		wins[min] += length; // 结束时刻
		if (wins[min] >= 17 * 60)return wins[min]++; // 如果这个人结束时时间下班了，下一个不再接入，和网上说的不太一样
		return wins[min]; // 结束时没有下班
	}
	else {
		Refresh(); // 刷新一次，递归一下，其实也就用刷新一次，因为一定会有空位的
		return Insert(length);
	}
}
int main(void) {
	unsigned customers = 0; // 客户数
	unsigned queries = 0; // 询问数
	scanf("%d %d %d %d", &windows, &capicity, &customers, &queries);
	for (size_t i = 0; i < windows; i++) {
		wins[i] = 8 * 60; // 时间置为8点
	}
	People* cust = new People[customers + 1]; // 给人开个数组
	for (size_t i = 1; i <= customers; i++) {
		scanf("%d", &cust[i].use);
		cust[i].end = Insert(cust[i].use); // 返回结束时间
		cust[i].start = cust[i].end - cust[i].use; // 得到开始时间
	}
	int ask = 0;
	for (size_t i = 0; i < queries; i++) {
		scanf("%d", &ask);
		// 客户时间是否在未关门前
		if ((cust[ask].start / 60 < 17)
			|| (cust[ask].start / 60 == 17 && cust[ask].start % 60 == 0)) {
			printf("%02d:%02d\n", cust[ask].end / 60, cust[ask].end % 60);
		}
		else{
			printf("Sorry\n");
		}
	}
	delete[] cust;
	return 0;
}