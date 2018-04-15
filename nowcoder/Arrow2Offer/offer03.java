/**
 * public class ListNode {
 * int val;
 * ListNode next = null;
 * <p>
 * ListNode(int val) {
 * this.val = val;
 * }
 * }
 */

import java.util.ArrayList;
import java.util.List;

public class Solution {
    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer> result = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        ListNode tempNode = listNode;
        while (tempNode != null) {
            temp.add(tempNode.val);
            System.out.println(tempNode.val);
            tempNode = tempNode.next;
        }
        System.out.println(temp);
        int size = temp.size();
        for (int i = size - 1; i >= 0; i--) {
            result.add(temp.get(i));
        }

        return result;
    }

    public static void main(String[] args) {
        ListNode a = new ListNode(67), b = new ListNode(0), c = new ListNode(24);

        a.next = b;
        b.next = c;
        Solution sol = new Solution();
        List<Integer> list = sol.printListFromTailToHead(a);
        System.out.println(list);
    }
}