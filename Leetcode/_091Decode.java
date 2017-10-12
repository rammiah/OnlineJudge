class Solution {
    int search(String str, int index) {
        int len = str.length();
        if (index >= len - 1) {
            return 1;
        }
        char c1 = str.charAt(index);
        char c2 = str.charAt(index + 1);
        int num = (c1 - '0') * 10 + c2 - '0';
        if (num >= 1 && num <= 26) {
            return search(str, index + 1) + 1;
        } else {
            return search(str, index + 1);
        }
    }

    public int numDecodings(String s) {
        if (s.isEmpty()) {
            return 0;
        }

        return search(s, 0);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.numDecodings(""));
    }
}
