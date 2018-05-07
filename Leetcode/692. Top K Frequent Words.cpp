class Solution {
	struct Pair{
		int cnt;
		string s;
		// constructor
		Pair(const int &n, const string &str)
		:cnt(n), s(str) {
		}
		friend bool operator<(const Pair &a, const Pair &b) {
			// compare a and b
			if (a.cnt > b.cnt) {
				return true;
			} else if (a.cnt == b.cnt) {
				return a.s < b.s;
			}
			return false;
		}
	};
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
  		map<string, int>m;
	  	// count words
		for (const auto &word : words) {
	  		++m[word];
	  	}
	  	vector<Pair> v;
	  	// sort words
		for (const auto &pair : m) {
			v.emplace_back(pair.second, pair.first);
		}
		sort(v.begin(), v.end());
		// get result
		vector<string> result;
		for (int i = 0; i < k; ++i) {
			result.emplace_back(v[i].s);
		}
		
		return result;
    }
};
