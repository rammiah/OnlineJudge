class Solution {
private:
    static std::vector<std::string> split_by_comma(const std::string &exp) {
        // 将字符串使用逗号分割
        // 表达式是被括号包着的
        std::string str = exp.substr(1, exp.length() - 2);
        int cnt = exp.length();
        // 开始截取字符串吧
        std::vector<std::string> words;
        int start = 1, end = 1;
        int level = 0;
        while (end < cnt) {
            if (exp[end] == ',') {
                if (level == 0) {
                    // 开始截取字符串
                    words.push_back(exp.substr(start, end - start));
                    start = end + 1;
                }
            } else if (exp[end] == ')') {
                level--;
            } else if (exp[end] == '(') {
                level++;
            }
            ++end;
        }
        // nrvo
        // 最后那个是没有','的
        words.push_back(exp.substr(start, end - start - 1));
        return words;
    }

public:
    bool parseBoolExpr(string exp) {
        // 解析bool表达式，看起来很有难度的样子
        // 表达式解析的重点就是如何正确的递归了吧，使用广度优先搜索？
        // 首先我们这个递归的函数有个要求，
        // 每个参数都是一个完全正确的bool表达式

        // 最简单，只有一个字母，判断即可
        if (exp.length() == 1) {
            return exp[0] == 't';
        }
        // 再长就是普通的表达式了
        // 获取子表达式
        std::vector<std::string> sub_exps = split_by_comma(exp.substr(1));
        std::vector<bool> exp_bools;
        bool res = false;
        // 进行逻辑判断
        switch (exp[0]) {
            case '&':
                // 与
                res = true;
                for (auto &sub_exp : sub_exps) {
                    res = res && parseBoolExpr(sub_exp);
                }
                break;
            case '|':
                // 或
                res = false;
                for (auto &sub_exp : sub_exps) {
                    res = res || parseBoolExpr(sub_exp);
                }
                break;
            case '!':
                // 非
                res = !parseBoolExpr(sub_exps[0]);
                break;
        }
        return res;
    }
};
