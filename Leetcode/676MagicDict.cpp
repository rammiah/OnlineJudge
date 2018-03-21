class MagicDictionary {
public:
    // map count of string to a set of string
    map<int, set<string>> str_map;
    /** Initialize your data structure here. */
    MagicDictionary() {
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for (const string & item : dict) {
            // add string to map
            str_map[item.length()].insert(item);
        }
    }
    
    bool search(const string &str, const set<string> &strs) {
        // count of different character
        int diff = 0;
        int size = strs.size();
        int len = str.length();
        // traverse strs to find only one different
        for (const string &v_str : strs) {
            diff = 0;
            for (int i = 0; i < len; ++i) {
                if (v_str[i] != str[i]){
                    ++diff;
                    // more than two
                    if (diff >= 2) {
                        break;
                    }
                }
            }
            // here diff is 0 or 1
            if (diff == 1) {
                // great
                return true;
            }
        }
        // sorry
        return false;
    }

    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        // yes
        return search(word, str_map[word.length()]);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */