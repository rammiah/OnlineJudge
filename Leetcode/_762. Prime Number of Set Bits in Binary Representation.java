class Solution {
    final int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

    public int countPrimeSetBits(int L, int R) {
        int result = 0;
        for (int i = L; i <= R; i++) {
            int bits = Integer.bitCount(i);
            for (Integer prime : primes) {
                if (bits == prime) {
                    ++result;
                    break;
                } else if (bits < prime) {
                    break;
                }
            }
        }

        return result;
    }
}