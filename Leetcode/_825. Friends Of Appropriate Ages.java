import java.util.Arrays;
import java.util.HashMap;

class Solution {
    boolean good(int A, int B) {
        if (B <= 0.5 * A + 7) {
            return false;
        }
        if (B > 100 && A < 100) {
            return false;
        }

        return true;
    }

    public int numFriendRequests(int[] ages) {
        if (ages == null || ages.length <= 1) {
            return 0;
        }

        HashMap<Integer, Integer> map = new HashMap<>();

        int ans = 0;
        Arrays.sort(ages);
        for (int i = 0; i < ages.length; i++) {
            if (map.containsKey(ages[i])) {
                ans += map.get(ages[i]);
                continue;
            }
            int sum = 0;
            for (int j = 0; j < ages.length && ages[j] <= ages[i]; j++) {
                if (i != j && good(ages[i], ages[j])) {
                    ++sum;
                }
            }
            map.put(ages[i], sum);
            ans += sum;
        }

        return ans;
    }
}