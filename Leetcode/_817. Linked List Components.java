class Solution {
    int[] list = new int[10001];
    int[] idx_helper = new int[10001];

    public int numComponents(ListNode head, int[] G) {
        // 链表中的值一定是0~N-1
//        Arrays.sort(G);
        if (G == null || G.length == 0) {
            return 0;
        }
        ListNode node = head;
        int idx = 0;
        while (node != null) {
            list[idx] = node.val;
            idx_helper[node.val] = idx;
            idx++;
            node = node.next;
        }

        int result = G.length;

        for (int i = 0; i < G.length; i++) {
            if (idx_helper[G[i]] < idx - 1) {
                int next = list[idx_helper[G[i]] + 1];
                //System.out.println(G[i] + " " + next);
                for (int j = 0; j < G.length; j++) {
                    if (G[j] == next) {
                        result--;
                        break;
                    }
                }
            }
        }

        return result;
    }
}
