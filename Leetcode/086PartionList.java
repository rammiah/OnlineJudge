import java.util.List;

//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    public ListNode partition(ListNode head, int x) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode big_equ = null, less = null;
        ListNode big_head = null, less_head = null;

        ListNode tmp_head = head;

        boolean first_less = true, first_big = true;

        while (head != null) {
            if (head.val >= x) {
                if (first_big) {
                    big_head = big_equ = new ListNode(head.val);
                    first_big = false;
                } else {
                    big_equ = big_equ.next = new ListNode(head.val);
                }
            } else {
                if (first_less) {
                    less_head = less = new ListNode(head.val);
                    first_less = false;
                } else {
                    less = less.next = new ListNode(head.val);
                }
            }
            head = head.next;
        }

        if (first_less) {
            less_head = tmp_head;
        } else {
            less.next = big_head;
        }

        return less_head;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        ListNode list = new ListNode(1);
        list.next = new ListNode(2);
        list.next.next = new ListNode(3);
        list = sol.partition(list, 2);
        while (list != null) {
            System.out.println(list.val);
            list = list.next;
        }
    }
}
