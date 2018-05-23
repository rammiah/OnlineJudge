_187. Repeated DNA Sequences.java
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        HashSet<String> repeated = new HashSet<>(), seen = new HashSet<>();
        int len = s.length() - 9;
        for (int i = 0; i < len; i++) {
            String str = s.substring(i, i + 10);
            if (!seen.add(str)) {
                repeated.add(str);
            }
        }

        return new ArrayList<>(repeated);
    }
}