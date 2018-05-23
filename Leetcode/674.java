class Solution {
    char[] chs;
    int cnt;

    private boolean isPalindrome(int start, int end) {
        while (start < end) {
            if (chs[start] != chs[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
    // 暴力肯定没问题，复杂度O(n^2)
    public int countSubstrings(String s) {
        // 单个字母
        cnt = s.length();
        chs = s.toCharArray();

        for (int i = 1; i < chs.length; i++) {
            for (int j = 0; j < chs.length - i; j++) {
                if (isPalindrome(j, i + j)) {
                    ++cnt;
                }
            }
        }

        return cnt;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.countSubstrings("aaa"));
    }
}

class BestSolution {
    int count;
    char[] chs;

    public int countSubstrings(String s) {
        if (s == null || s.length() == 0) return 0;
        chs = s.toCharArray();
        count = 0;
        for (int i = 0; i < chs.length; i++) { // i is the mid point
            extendPalindrome(i, i); // odd length;
            extendPalindrome(i, i + 1); // even length
        }

        return count;
    }

    private void extendPalindrome(int left, int right) {
        while (left >=0 && right < chs.length && chs[left] == chs[right]) {
            count++; left--; right++;
        }
    }
}