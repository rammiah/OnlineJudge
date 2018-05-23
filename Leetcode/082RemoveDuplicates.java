//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {
    // 递推实在太烧脑，还是递归吧
    public ListNode deleteDuplicates(ListNode head) {
        // null直接返回
        if (head == null) return null;
        ListNode temp = head;
        // next为null也直接返回
        if (temp.next == null) return head;
        // 如果是重了一下，好，那么这个就不要了
        if (temp.next.val == head.val) {
            while (temp != null && temp.val == head.val) {
                temp = temp.next;
            }
            // 直接到头，temp为null也是直接返回，或者返回不是那个数的
            head = deleteDuplicates(temp);
        } else {
            // 为head寻找下一个
            head.next = deleteDuplicates(head.next);
        }
        return head;
    }
}

