#include <cstdio>

int heights[10000];

void update(int &a, int b) {
	a = a > b ? a : b; 
} 

int main() {
	int cnt;
	scanf("%d", &cnt);
	for (int i = 0; i < cnt; ++i) {
		scanf("%d", &heights[i]);
	}
	
	int max = 0;
	
	for (int i = 0; i < cnt; ++i) {
		int left = i;
		int right = i;
		
		while (left >= 0 && heights[left] >= heights[i])--left;
		while (right < cnt && heights[right] >= heights[i])++right;
		update(max, (right - left - 1) * heights[i]);
	}
	
	printf("%d\n", max);
	
	return 0;
}
