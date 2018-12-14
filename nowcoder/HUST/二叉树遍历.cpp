#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <map>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Node {
    char val;

    Node *left, *right;
    Node(char ch) : val(ch), left(nullptr), right(nullptr){ }
};

Node *build(string& pre, string& in, int pl, int pr, int il, int ir) {
    if (pl > pr) {
        return nullptr;
    }
    else if (pl == pr) {
        return new Node(pre[pl]);
    }
    // 正常的解决方式
    // 首先取得中序第一个
    char mid = pre[pl];
    Node *node = new Node(mid);
    int idx = il;
    while (idx <= ir && in[idx] != mid) {
        ++idx;
    }
    // 递归建立左子树和右子树
    int len = idx - il;
    node->left = build(pre, in, pl + 1, pl + len, il, il + len - 1);
    node->right = build(pre, in, pl + len + 1, pr, il + len + 1, ir);
    
    return node;
}

void post_order(Node *node) {
    if (node != nullptr) {
        nullptr_t;
        post_order(node->left);
        post_order(node->right);
        cout << node->val;
    }
}

void free_tree(Node *node) {
    if (node != nullptr) {
        free_tree(node->left);
        free_tree(node->right);
        delete node;
    }
}

int main() {
    string pre, in;
    while (cin >> pre >> in) {
        Node *tree = build(pre, in, 0, pre.size() - 1, 0, pre.size() - 1);
        post_order(tree);
        cout << "\n";
        free_tree(tree);
    }
    
    return 0;
}
