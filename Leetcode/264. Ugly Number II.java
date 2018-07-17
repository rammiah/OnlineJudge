import java.util.HashSet;
import java.util.PriorityQueue;

class Solution {
    public int nthUglyNumber(int n) {
        long[] helper = new long[2000];
        PriorityQueue<Long> pq = new PriorityQueue<>();
        pq.add(1L);
        HashSet<Long> hs = new HashSet<>();
        hs.add(1L);
        int idx = 0;
        while (idx < n) {
            long small = pq.poll();
            if (small * 2 > small && hs.add(small * 2)) {
                pq.add(small * 2);
            }
            if (small * 3 > small && hs.add(small * 3)) {
                pq.add(small * 3);
            }
            if (small * 5 > small && hs.add(small * 5)) {
                pq.add(small * 5);
            }
            helper[idx++] = small;
        }

        return (int)helper[idx - 1];
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        System.out.println(sol.nthUglyNumber(1407));
        System.out.println(536870912);
    }
}
