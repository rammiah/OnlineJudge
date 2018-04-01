class Solution {
    bool match(const string &word, const string &S) {
        // 偷懒
        if (word == S) {
            return true;
        }
        int s_len = S.length();
        int w_len = word.length();
        // 放入长点的char数组防止报错
        char w_str[105] = {0};
        strcpy(w_str, word.c_str());
        char s_str[300] = {0};
        strcpy(s_str, S.c_str());
        if (s_len > w_len) {
            return false;
        }
        int s_idx = 0, w_idx = 0;
        while (w_idx < w_len && s_idx < s_len) {
            if (w_str[w_idx] != s_str[s_idx]) {
                return false;
            } else {
                // 此处只有一个字符
                if (w_str[w_idx] != w_str[w_idx + 1]) {
                    int len = 1;
                    while (s_str[s_idx + len] == w_str[w_idx]) {
                        // 找到不是的
                        // 记录有多长
                        ++len;
                    }
                    // 长度为2表示违反规则
                    if (len == 2) {
                        return false;
                    }
                    // s移动
                    s_idx += len;
                    // w向后移动
                    ++w_idx;
                } else {
                    // s有好几个字符相连
                    // 先记录长度
                    int len = 0;
                    while (word[w_idx] == word[w_idx + len]) {
                        len++;
                    }
                    // 这个时候的S里面必须连续多个比word的长
                    for (int i = 0; i < len; ++i) {
                        if (S[s_idx + i] != word[w_idx]) {
                            return false;
                        }
                    }
                    // S下标向后移动
                    while (S[s_idx] == word[w_idx]) {
                        ++s_idx;
                    }
                    w_idx += len;
                }
            }
        }
        // 都必须到尾部
        return !(w_idx < w_len || s_idx < s_len);

    }
public:
    int expressiveWords(string S, vector<string>& words) {
        int cnt = 0;
        for (const auto &word : words) {
            if (match(word, S)) {
                ++cnt;
            }
        }

        return cnt;
    }
};