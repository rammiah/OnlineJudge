class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int parts = minutesToTest / minutesToDie;
        return ceil(log2(buckets) / log2(parts + 1));
    }
};
