public class Solution {
        public boolean hasCycle(ListNode head) {
            if (head == null || head.next == null) {
                return false;
            }
            ListNode former = head;
            ListNode latter = head;
            // later is always after former
            while (former!=null && former.next != null) {
                former = former.next.next;
                latter = latter.next;
                if (former == latter) {
                    return true;
                }
            }
            return false;
        }
    }
