ass Solution {
    public:
    vector<int> getRow(int rowIndex) {
            vector<int> sol((unsigned long) (rowIndex + 1), 0);
            sol[0] = 1;
            for (long i = 1; i <= rowIndex; ++i) {
                        sol[i] = (int)(sol[i - 1] * (rowIndex - i + 1) / i);
                    }
            return sol;
        }
};
