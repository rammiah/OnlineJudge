import java.util.Collections;
import java.util.HashSet;
import java.util.Iterator;

class Solution {
    public int minimumLengthEncoding(String[] words) {
        if (words == null || words.length == 0) {
            return 1;
        }

        HashSet<String> strings = new HashSet<>();
        Collections.addAll(strings, words);
        
        int result = 0;
        Iterator<String> strs = strings.iterator();
        int size = 0;
        while (strs.hasNext()) {
            words[size++] = strs.next();
        }
        for (int i = 0; i < size; i++) {
            result += words[i].length() + 1;
            int max = 0;
            for (int j = 0; j < size; j++) {
                if (i != j && words[j].endsWith(words[i])) {
                    max = words[i].length() + 1;
                    break;
                }
            }

            result -= max;
        }

        return result;
    }

    public static void main(String[] args) {
        String[] strs = {"time", "me", "bell"};
        Solution sol = new Solution();
        System.out.println(sol.minimumLengthEncoding(strs));
    }
}