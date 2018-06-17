#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

using namespace std;
using ll = long long;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		for (int i = 1; i < A.size() - 1; ++i) {
			if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
				return i;
			}
		}

		return -1;
	}
};