class Solution {
public:
    string convertToTitle(int num) {
    	std::string str;
        while (num > 0) {
            --num;
            str.push_back(num % 26 + 'A');
            num /= 26;
        }
        std::reverse(str.begin(), str.end());
        return str;
    }
};
