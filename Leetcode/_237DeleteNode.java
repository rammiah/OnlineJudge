package Leetcode;

/**
 * Created by yaning on 17-6-1.
 */
public class _237DeleteNode {
    static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }

    static class Solution {
        public void deleteNode(ListNode node) {
            ListNode temp = node.next;
            node.val = temp.val;
            node.next = temp.next;
        }
    }


}
