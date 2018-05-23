
//Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return null;
        int length = 1;
        ListNode temp = head;
        while (temp.next != null){
            ++length;
            temp = temp.next;
        }
        ListNode end = temp;
        k %= length;
        temp = head;
        for (int i = 0; i < length - k - 1; i++) {
            temp = temp.next;
        }
        end.next = head;
        head = temp.next;
        temp.next = null;

        return head;
    }

    public static void main(String[] args) {
        ListNode head = new ListNode(1);
        ListNode t = head;
        for (int i = 2; i < 10; i++) {
            t = t.next = new ListNode(i);
        }
        t = new Solution().rotateRight(head, 17);
        head = t;
        while (t != null) {
            System.out.println(t.val);
            t = t.next;
        }
    }
}

