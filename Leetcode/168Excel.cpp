class Solution {
private: 
	const int allChar = 26;
public:
    string convertToTitle(int n) {
    	--n;
    	if (n < allChar) {
    		return "" + (char)(n + 'A');
    	} else {
    		return convertToTitle(n / allChar)
    		 + (char)(n % allChar + 'A');
    	}
    }
};