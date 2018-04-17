class Trie {
private:
    struct Node {
        Node *next[26];
        bool is_word = false;
        Node() {
            for (int i = 0; i < 26; ++i) {
                next[i] = NULL;
            }
        }
    };

    Node *find(const string &str) {
        int len = str.length();
        Node *node = root;
        for (int i = 0; i < len && node != NULL; ++i) {
            node = node->next[str[i] - 'a'];
        }

        return node;
    }
    
    Node *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();    
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *node = root;
        int len = word.length();
        for (int i = 0; i < len; ++i) {
            if (node->next[word[i] - 'a'] == NULL) {
                node->next[word[i] - 'a'] = new Node();
            }
            node = node->next[word[i] - 'a'];
        }
        node->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *node = find(word);
        return node != NULL && node->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix) != NULL;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s)
    {
        TrieNode *p = root;
        for(int i = 0; i < s.size(); ++ i)
        {
            if(p -> next[s[i] - 'a'] == NULL)
                p -> next[s[i] - 'a'] = new TrieNode();
            p = p -> next[s[i] - 'a'];
        }
        p -> is_word = true;
    }

    // Returns if the word is in the trie.
    bool search(string key)
    {
        TrieNode *p = find(key);
        return p != NULL && p -> is_word;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix)
    {
        return find(prefix) != NULL;
    }

private:
    TrieNode* find(string key)
    {
        TrieNode *p = root;
        for(int i = 0; i < key.size() && p != NULL; ++ i)
            p = p -> next[key[i] - 'a'];
        return p;
    }
};

 */
