class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> vs;
        sort(timePoints.begin(), timePoints.end());
        int hour, minute;
        for (auto &time : timePoints) {
            sscanf(time.c_str(), "%d:%d", &hour, &minute);
            minute += hour * 60;
            vs.push_back(minute);
        }
        vs.push_back(vs.front() + 24 * 60);
        int res = 24 * 60;
        for (int i = 1; i < vs.size(); ++i) {
            res = min(vs[i] - vs[i - 1], res);
        }
        return res;
    }
};