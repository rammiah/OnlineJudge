#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Node{
    int index;
    string source;
    string target;
    Node(int i, string s, string t):index(i), source(s), target(t){}
    friend bool operator<(const Node &a, const Node &b) {
        return a.index < b.index;
    }
};

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        string result = S;
        int size = indexes.size();
        int last = 0;
        vector<Node> nodes;
        for (int i = 0; i < size; ++i) {
            nodes.emplace_back(indexes[i], sources[i], targets[i]);
        }
        sort(nodes.begin(), nodes.end());
        int add_len = 0;
        for (auto &node : nodes) {
            if (S.find(node.source, node.index) == node.index) {
                // 可以替换
                // 个人感觉不如直接append
                result.replace(node.index + add_len, 
                node.source.length(), node.target);
                add_len += node.target.length() - node.source.length();
            }
        }

        return result;
    }
};