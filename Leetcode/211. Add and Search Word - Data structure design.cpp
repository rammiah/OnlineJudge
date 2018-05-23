// Leetcode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class WordDictionary {
    static const int Radix = 26;
    struct Node {
        // char ch;
        bool is_word = false;
        Node *next[Radix];
        Node() {
            for (auto &n : next) {
                n = nullptr;
            }
        }
    };
    Node *root = nullptr;
    
    bool search(Node *node, const string &str, int idx) {
        if (node == nullptr) {
            return false;
        }
        int len = str.length();
        if (idx == len) {
            return node->is_word;
        }

        // 开始检测是否有以当前字母开头的word
        for (int i = idx; i < len; ++i) {
            if (str[i] == '.') {
                for (int j = 0; j < Radix; ++j) {
                    if (search(node->next[j], str, i + 1)) {
                        return true;
                    }
                }
                return false;
            }
            if (node->next[str[i] - 'a'] == nullptr) {
                return false;
            }
            node = node->next[str[i] - 'a'];
        }

        return node->is_word;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        // 加入单词
        // int len = word.length();
        Node *node = root;
        for (auto &ch : word) {
            if (node->next[ch - 'a'] == nullptr) {
                node->next[ch - 'a'] = new Node();
            }
            node = node->next[ch - 'a'];
        }
        // 插入单词
        node->is_word = true;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        // 这个用递归好一点
        Node *node = root;
        int len = word.length();
        for (int i = 0; i < len; ++i) {
            if (word[i] == '.') {
                for (int j = 0; j < Radix; ++j) {
                    if (search(node->next[j], word, i + 1)) {
                        return true;
                    }
                }
                return false;
            }
            if (node->next[word[i] - 'a'] == nullptr) {
                return false;
            }
            node = node->next[word[i] - 'a'];
        }

        return node->is_word;
    }
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary obj = new WordDictionary();
* obj.addWord(word);
* bool param_2 = obj.search(word);
*/

int main() {
    vector<string> strs = { "bad", "dad", "mad" };
    WordDictionary d;
    for (auto &str : strs) {
        d.addWord(str);
    }
    cout << d.search("pad") << "\n";
    cout << d.search("bad") << "\n";
    cout << d.search(".ad") << "\n";
    cout << d.search("b..") << "\n";

    return 0;
}

