package Leetcode;

/**
 * Created by yaning on 17-5-30.
 */
public class _019RemoveNode {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    public static void main(String[] args) {
        ListNode n1 = new ListNode(1);
        ListNode n2 = new ListNode(2);
        n1.next = n2;
        ListNode n3 = new ListNode(3);
        n2.next = n3;
        ListNode n4 = new ListNode(4);
        n3.next = n4;
        ListNode n5 = new ListNode(5);
        n4.next = n5;
        n5.next = null;
        Solution sol = new Solution();
//        sol.removeNthFromEnd(n1, 1);
        ListNode l = sol.removeNthFromEnd(n1, 3);

        while (l != null) {
            System.out.println(l.val);
            l = l.next;
        }

    }

    static class Solution {
        public ListNode removeNthFromEnd(ListNode head, int n) {
            if (n == 0) {
                return head;
            }
            ListNode pre = new ListNode(0);
            pre.next = head;
            ListNode temp = head;
            for (int i = 0; i < n; i++) {
                temp = temp.next;
            }
            while (temp != null) {
                temp = temp.next;
                pre = pre.next;
            }
            if (pre.next == head) {
                return head.next;
            }
            pre.next = pre.next.next;
            return head;
        }
    }
}
