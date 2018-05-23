#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node {
    char ch;
    int val;
    friend bool operator<(const Node &a, const Node &b) {
        return a.val < b.val;
    }
};


class Solution {
public:
    string customSortString(string S, string T) {
        int vals[26] = {0};
        int s_len = S.length();
        for (int i = 0; i < s_len; ++i) {
            vals[S[i] - 'a'] = i;
        }

        vector<Node> chs;
        Node n;
        for (auto &c : T) {
            n.ch = c;
            n.val = vals[c - 'a'];
            chs.push_back(n);
        }
        sort(chs.begin(), chs.end());
        string result = T;
        int idx = 0;
        for (auto &node : chs) {
            result[idx++] = node.ch;
        }

        return result;
    }
};