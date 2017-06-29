package fork_join;

import java.util.List;

/**
 * Time: 29/06/17 08:10
 * Created by yaning.
 * School: HUST
 * Email: wangyaning6166@gmail.com
 */
public class _083RemoveDuplicates {

    //      Definition for singly-linked list.
    public class ListNode {
        int val;
        ListNode next;

        ListNode(int x) {
            val = x;
        }
    }

    public class Solution {
        public ListNode deleteDuplicates(ListNode head) {
            if (head == null || head.next == null) {
                return head;
            }
            ListNode mov = head.next;
            ListNode slow = head;
            while (mov != null) {
                if (mov.val != slow.val) {
                    slow.next = mov;
                    slow = slow.next;
                }
                mov = mov.next;
            }
            slow.next = null; // [1,1]
            return head;
        }
    }
}
