package Leetcode;

/**
 * Time: 28/06/17 21:35
 * Created by yaning.
 * School: HUST
 * Email: wangyaning6166@gmail.com
 */
public class _058LastWordLength {
    public int lengthOfLastWord(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }
        String[] words = s.split(" ");
        if (words.length > 0) {
            return words[words.length - 1].length();
        }
        return 0;
    }
}
