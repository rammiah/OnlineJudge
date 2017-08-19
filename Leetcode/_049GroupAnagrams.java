import java.util.*;

class Solution {
    int[] hash = new int[26];

    public Solution() {
        Random random = new Random();
        for (int i = 0; i < 26; i++) {
            hash[i] = random.nextInt();
        }
    }

    // 使用hashmap就那样了
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<Integer, List<String>> map = new HashMap<>();
        int hash_key = 0;
        for (String str : strs) {
            hash_key = getHash(str);
            if (map.containsKey(hash_key)) {
                map.get(hash_key).add(str);
            } else {
                List<String> list = new ArrayList<>();
                list.add(str);
                map.put(hash_key, list);
            }
        }
        List<List<String>> result = new ArrayList<>();
        for (int key : map.keySet()) {
            result.add(map.get(key));
        }
        return result;
    }

    private int getHash(String str) {
        int result = 0;
        for (char ch : str.toCharArray()) {
            result += hash[ch - 'a'];
        }
        return result;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        String[] strings = {"eat", "tea", "tan", "ate", "nat", "bat"};
        for (List<String> strs : sol.groupAnagrams(strings)) {
            System.out.println(strs);
        }
    }
}
