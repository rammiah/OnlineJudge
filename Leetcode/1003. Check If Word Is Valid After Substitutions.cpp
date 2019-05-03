class Solution {
public:
    bool isValid(string s) {
        // 就是普通的查找和删除吗？
        while (s.size() > 0) {
            int pos = s.find("abc");
            if (pos == string::npos) {
                return false;
            }
            s.erase(pos, 3);
            // cout << s << "\n";
        }
        return true;
    }
};
