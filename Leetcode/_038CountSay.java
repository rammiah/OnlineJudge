package Leetcode;

/**
 * Time: 28/06/17 21:20
 * Created by yaning.
 * School: HUST
 * Email: wangyaning6166@gmail.com
 */
public class _038CountSay {

    public static void main(String[] args) {
        _038CountSay say = new _038CountSay();
        for (int i = 0; i < 10; i++) {
            System.out.println(i + " "  + say.countAndSay(i));
        }
    }

    public String countAndSay(int n) {
        if (n <= 0) {
            return "";
        }
        String now = "1";
        for (int i = 1; i < n; i++) {
            now = getSay(now);
        }
        return now;
    }

    String getSay(String s) {
        StringBuilder sb = new StringBuilder();
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count++;
            if (i + 1 < s.length()) {
                if (s.charAt(i) != s.charAt(i + 1)) {
                    sb.append(count).append(s.charAt(i));
                    count = 0;
                }
            } else if (i + 1 == s.length()) {
                sb.append(count).append(s.charAt(i));
            }
        }
        return sb.toString();
    }
}
