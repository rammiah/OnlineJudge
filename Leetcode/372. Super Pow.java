class Solution {
    // 费马小定理
    public int superPow(int a, int[] b) {
        // a是一个数字，b是一个存储在数组的数字
        // 计算mod 1337
        // 坑我，mod 1140
        int numb = 0;
        for (int i = 0; i < b.length; i++) {
            numb = (numb * 10 + b[i]) % 1140;
        }
        // 计算a^b mod 1337
        long result = 1;
        for (int i = 0; i < numb; ++i) {
            result = result * a % 1337;
        }

        return (int) result;
    }
}