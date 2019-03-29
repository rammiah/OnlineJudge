class RecentCounter {
	// hello
	int32_t nums[10005];
	int32_t back, front;
public:
	RecentCounter() : back(0), front(0) {
		memset(nums, 0, sizeof(nums));
	}

	int ping(int t) {
		nums[back++] = t;
		t -= 3000;
		while (nums[front] < t) {
			++front;
		}
		return back - front;
	}
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */