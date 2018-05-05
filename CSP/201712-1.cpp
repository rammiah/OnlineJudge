#include <cstdio>
#include <map>
#include <climits>

int main() {
	using std::map;
	int cnt;
	scanf("%d", &cnt);
	int num;
	map<int, int> m;
	int result = INT_MAX;
	while (cnt--) {
		scanf("%d", &num);
		++m[num];
		if (m[num] >= 2) {
			result = 0;
			printf("%d\n", result);
			return 0;
		}
	}
	
	map<int, int>::iterator it = m.begin(), end = m.end();
	int old = it->first;
	++it;
	while (it != end) {
		result = result < it->first - old ? result : it->first - old;
		old = it->first;
		++it;
	}
	 
	printf("%d\n", result);
	
	return 0;
} 
