#include <cstdio>
#include <vector>

int main() {
	using std::vector;
	int cnt, cycle;
	scanf("%d %d", &cnt, &cycle);
	vector<int> out(cnt, 0);
	for (int i = 0; i < cnt; ++i) {
		out[i] = i + 1;
	}
	
	int num = 0;
	vector<int>::iterator it = out.begin();
	while (out.size() > 1) {
		bool found = false;
		while (!found) {
			//printf("%d\n", *it);
			++num;
			if (num % cycle == 0 || num % 10 == cycle) {
				//	printf("del: %d\n", *it);
				// erase返回值是下一个元素的迭代器 
				it = out.erase(it);
				if (it == out.end()) {
					it = out.begin();
				}
				found = true;
			} else {
				++it;
				if (it == out.end()) {
					it = out.begin();
				}
			}
		}
	}
	
	printf("%d\n", out[0]);

	return 0;
} 

