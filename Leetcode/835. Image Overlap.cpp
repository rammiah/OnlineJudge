class Solution {
    std::bitset<900> move(std::bitset<900> cpy, int row, int col, int len) {
        if (row < 0) {
            row = -row;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < len; j++) {
                    cpy.set(j * len + i, 0);
                }
            }
            cpy >>= row;
        }
        else if (row > 0) {
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < len; j++) {
                    cpy.set((j + 1) * len - i - 1, 0);
                }
            }
            cpy <<= row;
        }

        if (col < 0) {
            col = -col;
            for (int i = 0; i < col; i++) {
                for (int j = 0; j < len; j++) {
                    cpy.set(i * len + j, 0);
                }
            }
            cpy >>= (col * len);
        }
        else if (col > 0){
            for (int i = 0; i < col; i++) {
                for (int j = 0; j < len; j++) {
                    cpy.set((len - i - 1) * len + j, 0);
                }
            }
            cpy <<= (col * len);
        }

        return cpy;
    }

public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        std::bitset<900> bitsA, bitsB;
        // 将B写入bitsB
        int len = B.size();

        for (int row = 0; row < len; row++) {
            for (int col = 0; col < len; col++) {
                bitsB.set(row * len + col, B[row][col]);
                bitsA.set(row * len + col, A[row][col]);
            }
        }

        int max = 0;

        // move(bitsA, 0, 1, len);

        for (int i = 1 - len; i < len; i++) {
            for (int j = 1 - len; j < len; j++) {
                int val = (bitsB & move(bitsA, i, j, len)).count();
                max = std::max(val, max);
            }
        }

        return max;
    }
};
