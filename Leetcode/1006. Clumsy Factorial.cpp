const char ops[] = {'*', '/','+', '-'};

class Solution {
public:
    
    int clumsy(int N) {
        // a little hard, medium
        int res = N;
        int n;
        int op = 0;
        int carry = 0;
		//  整体处理，降低难度
        for (int i = 0; i < N - 1;) {
            // cout << ops[i % 4] << "\n";
            n = N - i - 1;
            if (ops[i % 4] == '+') {
                res += n;
                i++;
            } else if (ops[i % 4] == '-') {
                if (i + 3 < N - 1) {
                    res -= n * (n - 1) / (n - 2);  
                    i += 3;
                } else if (i + 1 == N - 1) {
                    res -= 1;
                    i++;
                } else if (i + 2 == N - 1) {
                    res -= 2;
                    i += 2;
                } else if (i + 3 == N - 1) {
                    res -= 3 * 2;
                    i += 3;
                }
            } else if (ops[i % 4] == '*') {
                // 只有第一次会碰到*，但是还是要判断一下长度
                if (i + 2 < N - 1) {
                    res = res * n / (n - 1);
                    i += 2;
                } else if (i + 1 == N - 1) {
                    res *= n;
                    i++;
                } else if (i + 2 == N - 1) {
                    res = res * n / (n - 1);
                    i += 2;
                }
            }
        }
        
        return res;
    }
};