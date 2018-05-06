class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
    	vector<int> temp(2, 0);
        vector<vector<int>> result;
        int last = 0;
        int curr = 0;
        int len = S.length();
        while (curr < len) {
		    while (curr < len && S[curr] == S[last]) {
		    	curr++;
			}
			
			if (curr - last >= 3) {
				temp[0] = last;
				temp[1] = curr - 1;
				result.push_back(temp);
			}
			//std::cout << curr - 1 << "\n";
			last = curr;
			curr++;
		}
		
		return result;
    }
};

