#include <string>

using namespace std;

class MapSum {
    static const int Radix = 256;
    struct Node {
        int cnt = 0;
        bool is_word = false;
        Node *next[256];
        // 处理指针域
        Node() {
            for (int i = 0; i < Radix; ++i) {
                next[i] = nullptr;
            }
        }
    };

    // 查询是否存放了这个词
    bool contain(string str) {
        int len = str.length();
        Node *node = root;
        for (int i = 0; i < len; ++i) {
            if (node->next[str[i]] == nullptr) {
                return false;
            }
            node = node->next[str[i]];
        }
        return node->is_word;
    }

    Node *root = nullptr;

public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        // 插入相同的值需要替换而不是直接加上去
        if (contain(key)) {
            val = val - sum(key);
        }
        int len = key.length();
        Node *node = root;
        for (int i = 0; i < len; ++i) {
            if (node->next[key[i]] == nullptr) {
                node->next[key[i]] = new Node();
            }
            node->cnt += val;
            node = node->next[key[i]];
        }
        node->cnt += val;
        node->is_word = true;
    }
    
    int sum(string prefix) {
        int len = prefix.length();
        Node *node = root;
        for (int i = 0; i < len; ++i) {
            if (node->next[prefix[i]] == nullptr) {
                return 0;
            }
            node = node->next[prefix[i]];
        }

        return node->cnt;
    }
};