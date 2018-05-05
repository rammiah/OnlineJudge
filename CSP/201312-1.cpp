#include <cstdio>
#include <map>

int main() {
	int cnt;
	scanf("%d", &cnt);
	using std::map;
	map<int, int> m;
	int num;
	while (cnt--) {
		scanf("%d", &num);
		++m[num];
	}
	
	int max = -1, result;
	map<int, int>::iterator p = m.begin(), end = m.end();
	while(p != end) {
		if (p->second > max) {
			max = p->second;
			result = p->first;
		}
		++p;
	}
	printf("%d\n", result);
	
	return 0;
}
