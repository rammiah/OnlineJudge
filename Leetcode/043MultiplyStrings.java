public class Solution {
    public String multiply(String num1, String num2) {
        if (num1 == null || num2 == null || num1.length() * num2.length() == 0) return "0";
        int left = 0;
        int temp = 0;
        int[] result = new int[num1.length() + num2.length()];
        char[] num2_chars = num2.toCharArray();
        char[] num1_chars = num1.toCharArray();
        // index为从0开始增加
        int index = 0;
        for (int i = num1_chars.length - 1; i >= 0; --i) {
            int number = num1_chars[i] - '0';
            // 作为临时开始下标
            int numIndex = index;
            left = 0;
            for (int j = num2_chars.length - 1; j >= 0; --j) {
                temp = number * (num2_chars[j] - '0') + left + result[numIndex];
                result[numIndex] = temp % 10;
                left = temp / 10;
                ++numIndex;
            }
            result[numIndex] = left;
            ++index;
        }
        StringBuilder builder = new StringBuilder();
        index = result.length - 1;
        while (index > 0 && result[index] == 0) --index;
        while (index >= 0) {
            builder.append(result[index--]);
        }
        return builder.toString();
    }
}
