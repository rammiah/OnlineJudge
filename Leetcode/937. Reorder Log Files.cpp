int iorder = 0;
struct Mylog {
    // 字母的按照内容排序
    // 数字的按照原来顺序，不要排序
    string str;
    int order;
    string content;
    int type;
    Mylog(const string &s){
        stringstream ss(s);
        str = s;
        order = iorder++;
        ss >> content;
        std::getline(ss, content);
        content.erase(0, 1);
        //  判断类型
        type = isdigit(content[0]);
        // cout << type << " " << content[0] << " " << content  << "\n";
    }
    
    friend bool operator<(const Mylog &a, const Mylog &b) {
        if (a.type == 1 && b.type == 1) {
            return a.order < b.order;
        } else if (a.type == 1 && b.type == 0) {
            return false;
        } else if (a.type == 0 && b.type == 1) {
            return true;
        }
        return a.content < b.content;
    }
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<Mylog> vlogs;
        vlogs.reserve(logs.size());
        for (auto &s : logs) {
            vlogs.emplace_back(s);
        }
        sort(vlogs.begin(), vlogs.end());
        int len = logs.size();
        for (int i = 0; i < len; ++i) {
            logs[i] = std::move(vlogs[i].str);
        }
        
        return logs;
    }
};
