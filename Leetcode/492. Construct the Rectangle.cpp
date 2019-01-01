class Solution {
public:
    vector<int> constructRectangle(int area) {
        // 果然让小的一方变化比较快
        int w = std::sqrt(area);
        while (area % w != 0) {
            w--;
        }
        return {area / w, w};
    }
};

