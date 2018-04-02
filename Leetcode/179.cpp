class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string result;
        vector<string> num_strs;
        // 先转化为字符串
        for (const auto &num : nums) {
            num_strs.push_back(to_string(num));
        }
        // 排序，传入自定义排序函数
        sort(num_strs.begin(), num_strs.end(), [](string &a, string &b){return a + b > b + a;});
        for (auto &num_str : num_strs) {
            result.append(num_str);
        }
        int index = 0;
        // 0, 00
        // 去除前置0
        while (result[index] == '0' && result.length() - index > 1) {
            ++index;
        }

        return result.substr(index);
    }
};