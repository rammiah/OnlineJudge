#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e6;

int main() {
	// freopen("1.txt", "r", stdin);
	int T;
	int n, d;
	cin >> T;
	while (T--) {
		cin >> n >> d;
		vector<int> p(n + 1, 0);
		vector<int> dp(n + 1, 0);
		vector<int> Max(MAXN, 0);
		for (int i = 1; i <= n; i++)
			cin >> p[i];
		for (int i = 1; i <= n; i++) {
			int l = max(0, p[i] - d);
			int r = p[i] + d;
			int num = 0;
			for (int j = l; j <= r; j++)
				num = max(num, Max[j]);
			dp[i] = num + 1;
			Max[p[i]] = max(Max[p[i]], dp[i]);
		}
		cout << *max_element(dp.begin(), dp.end()) << endl;
	}
    
	return 0;
}