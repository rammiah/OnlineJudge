class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> cnts;
        char str[1000];
        int times;
        string s;
        for (const auto &cp : cpdomains) {
            sscanf(cp.c_str(), "%d %s", &times, str);
            int index = -1;
            s = str;
            cnts[s] += times;
            while ((index = cp.find('.', index + 1)) != -1) {
                cnts[cp.substr(index + 1)] += times;
            }
        }

        vector<string> res;
        for (const auto &it : cnts) {
            s = to_string(it.second) + " " + it.first;
            res.push_back(s);
        }

        return res;
    }
};