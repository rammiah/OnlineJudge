// Jisuanke.cpp : Defines the entry point for the console application.
//
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
// using namespace std;
using std::swap;
using std::strlen;
using std::scanf;
using std::printf;

class Trie {
private:
    struct Node {
        int cnt = 0;
        int w_cnt = 0;
        Node *next[26];
        bool is_word = false;
        Node() {
            for (int i = 0; i < 26; ++i) {
                next[i] = nullptr;
            }
        }
    };
    void _delete(const char str[], int cnt) {
        int len = strlen(str);
        Node *node = root;
        for (int i = 0; i < len; ++i) {
            node->cnt -= cnt;
            node = node->next[str[i] - 'a'];
        }
        node->is_word = false;
        node->w_cnt = 0;
        node->cnt -= cnt;
    }
    Node *search(const char str[]) {
        Node *node = root;
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            if (node->next[str[i] - 'a'] == nullptr) {
                return nullptr;
            }
            node = node->next[str[i] - 'a'];
        }

        return node;
    }
    Node *root = new Node();
public:
    void insert(const char str[], int cnt) {
        Node *node = root;
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            if (node->next[str[i] - 'a'] == nullptr) {
                node->next[str[i] - 'a'] = new Node();
            }
            node->cnt += cnt;
            node = node->next[str[i] - 'a'];
        }
        node->is_word = true;
        node->cnt += cnt;
        node->w_cnt += cnt;
    }

    int query(const char str[]) {
        Node *node = root;
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            if (node->next[str[i] - 'a'] == nullptr) {
                return 0;
            }
            node = node->next[str[i] - 'a'];
        }

        return node == nullptr ? 0 : node->cnt;
    }

    bool _delete(const char str[]) {
        Node *node = search(str);
        if (node == nullptr || !node->is_word) {
            return false;
        }
        _delete(str, node->w_cnt);
        return true;
    }
};

void reverse(char str[]) {
    int len = strlen(str);
    int left = 0, right = len - 1;
    while (left < right) {
        swap(str[left], str[right]);
        left++;
        right--;
    }
}

int main() {
   // freopen("C:\\Users\\Yaning Wang\\Documents\\GitHub\\OnlineJudge\\etc\\2.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        Trie tree;
        int ops;
        scanf("%d", &ops);
        // string op, str;
        int cnt;
        char operation[20];
        char str[10005];

        while (ops--) {
            scanf("%s", operation);
            if (operation[0] == 'i') {
                scanf("%s %d", str, &cnt);
                reverse(str);
                tree.insert(str, cnt);
            }
            else if (operation[0] == 'q') {
                scanf("%s", str);
                reverse(str);
                printf("%d\n", tree.query(str));
            }
            else {
                scanf("%s", str);
                reverse(str);
                if (!tree._delete(str)) {
                    printf("Empty\n");
                }
            }
        }
    }

    return 0;
}