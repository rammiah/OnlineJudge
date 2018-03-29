class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) {
            return 0;
        }
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int g_size = g.size(), s_size = s.size();
        // 双指针法
        int cookie = 0, child = 0;
        while (cookie < s_size && child < g_size) {
            if (s[cookie] >= g[child]) {
                cookie++;
                child++;
            } else {
                cookie++;
            }
        }

        return cookie;
    }
};