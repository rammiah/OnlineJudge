class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        if (list1.size() > list2.size()) {
            list1.swap(list2);
        }
        for (int i = 0; i < list2.size(); ++i) {
            m[list2[i]] = i;
        }
        int value = INT_MAX;
        vector<string> result;
        for (int i = 0; i < list1.size(); ++i) {
            if (m.count(list1[i])) {
                if (m[list1[i]] + i < value) {
                    result.clear();
                    value = m[list1[i]] + i;
                    result.push_back(list1[i]);
                }
                else if (m[list1[i]] + i == value) {
                    result.push_back(list1[i]);
                }
            }
        }
        return result;
    }
};