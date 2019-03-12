static char content[20005], name[55];

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<std::string, std::vector<string>> m;
        for (auto path : paths) {
            // 解析路径及其内容
            string dir;
            stringstream ss(path);
            ss >> dir;
            dir.push_back('/');

            // cout << dir;
            string tmp;
            char c;
            while (ss >> tmp) {
                sscanf(tmp.c_str(), "%[^(]%c%[^)]", name, &c, content);
                // cout << name << " " << content << "\n";
                m[content].push_back(dir + name);
            }
        }
        std::vector<std::vector<string>> res;
        for (auto &p : m) {
            if (p.second.size() > 1) {
                res.push_back(std::move(p.second));
            }
        }
        return res;
    }
};
