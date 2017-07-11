
class Solution {
    // 这个需要是单射
    public boolean wordPattern(String pattern, String str) {
        String[] strs = str.split(" ");
        char[] pats = pattern.toCharArray();
        Map<Character, String> c2s = new HashMap<>();
        Map<String, Character> s2c = new HashMap<>();
        if (strs.length != pats.length) return false;
        for (int i = 0; i < pats.length; ++i) {
            if (c2s.containsKey(pats[i]) || s2c.containsKey(strs[i])) {
                if (s2c.containsKey(strs[i]) && s2c.get(strs[i]) == pats[i] && 
                        c2s.containsKey(pats[i]) && c2s.get(pats[i]).equals(strs[i])) {
                    continue;
                }
                return false;
            } else {
                c2s.put(pats[i], strs[i]);
                s2c.put(strs[i], pats[i]);
            }
        }
        return true;
    }
}
