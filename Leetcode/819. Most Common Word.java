import java.util.HashMap;

class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        HashMap<String, Integer>map = new HashMap<>();
        String[] words = paragraph.toLowerCase().split("[,.!? ;`'\"]+");
        for (String str : words) {
            if (map.containsKey(str)) {
                map.put(str, map.get(str) + 1);
            } else {
                map.put(str, 1);
            }
        }

        for (String str : banned) {
            str = str.toLowerCase();
            if (map.containsKey(str)) {
                map.remove(str);
            }
        }

        String result = "";
        int max = 0;
        for (HashMap.Entry<String, Integer> pair : map.entrySet()) {
            if (pair.getValue() > max) {
                max = pair.getValue();
                result = pair.getKey();
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.mostCommonWord("Bob. hIt, balL", new String[]{"bob", "hit"}));
    }
}