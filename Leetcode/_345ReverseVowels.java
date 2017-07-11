class Solution {
    // 判断元音
    private boolean isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';

    }
    public String reverseVowels(String s) {
        // 坑到吐血
        char[] chars = s.toCharArray();
            int left = 0;
            int right = chars.length - 1;
            while (left < right) {
                while (left < right && !isVowel(chars[left]))left++;
                while (left < right && !isVowel(chars[right]))right--;
                // 在这里坑了一会
                if (left < right) {
                    char temp = chars[left];
                    chars[left] = chars[right];
                    chars[right] = temp;
                    left++;
                    right--;
                }
            }
        return String.valueOf(chars);
    }
}
