class Solution {
private:
    struct Node {
        char ch;
        bool is_end = false;
        Node *next[26]{}; // 这26个默认都是nullptr

        explicit Node(char ch) : ch(ch) {}
    };

    class Trie {
        // 根节点
        Node *root = new Node(0);
    private:
        Node *insert(const std::string &str, int idx, Node *root) {
            if (root == nullptr) {
                root = new Node(str[idx]);
            }
            // 已经是根节点，结束向下拓展
            if (root->is_end) {
                return root;
            }
            // 到达字符串的结束位置
            if (idx == str.size() - 1) {
                // 结束了
                root->is_end = true;
            } else {
                idx++;
                int i = str[idx] - 'a';
                root->next[i] = insert(str, idx, root->next[i]);
            }
            return root;
        }

        bool successor(const std::string &str, std::string &res, int idx, Node *node) {
            // 最开始没有考虑到给的字符串比树上的短的情况
            if (node == nullptr || idx >= str.size()) {
                return false;
            }
            res.push_back(node->ch);
            if (node->is_end) {
                // 确认存在前缀
                return true;
            } else {
                // 递归计算前缀，向下走一层
                return successor(str, res, idx + 1, node->next[str[idx + 1] - 'a']);
            }
        }

        void delete_node(Node *node) {
            if (node != nullptr) {
                for (auto &i : node->next) {
                    delete_node(i);
                }
                delete (node);
            }
        }

    public:
        // 插入字典
        void insert(const std::string &str) {
            int i = str[0] - 'a';
            root->next[i] = insert(str, 0, root->next[i]);
        }

        // 查找前缀，不存在返回原字符串
        std::string successor(const std::string &str) {
            // 寻找最短前置
            std::string res;
            if (successor(str, res, 0, root->next[str[0] - 'a'])) {
                return res;
            }
            return str;
        }

        ~Trie() {
            // 清理空间，虽然没有什么用
            delete_node(root);
        }
    };

public:
    string replaceWords(vector<string> &dict, string sentence) {
        // 典型字典树
        // 首先使用dict构建Trie
        Trie trie;
        for (auto &s : dict) {
            trie.insert(s);
        }
        // 替换开始
        // 这个替换有点难度，使用stringstream得到每个单词吧，
        // 反正都是字母和空格
        // 使用一个string初始化sstream
        std::stringstream ss(sentence);
        std::string word;
        ss >> word;
        std::string res = trie.successor(word);
        while (ss >> word) {
            word = trie.successor(word);
            res.append(" " + word);
        }
        return res;
    }
};
