#include <iostream>
#include <vector>
#include <algorithm>

bool max(const std::string &a, const std::string &b) {
    return a + b > b + a;
}

int main(void) {
    int str_cnt = 0;
    std::string res(""), temp("");
    std::vector<std::string> strs;
    while (std::cin >> str_cnt) {
        res = "";
        strs.clear();
        for (int i = 0; i < str_cnt; ++i) {
            std::cin >> temp;
            strs.push_back(temp);
        }
        
        std::sort(strs.begin(), strs.end(), max);
        for (const auto &t : strs) {
            res.append(t); 
        }
        
        std::cout << res << std::endl;
    }
    
    return 0;
}
