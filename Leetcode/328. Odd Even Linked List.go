/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func oddEvenList(head *ListNode) *ListNode {
    if head == nil || head.Next == nil {
        return head
    }

    headTmp := head.Next

    next0, next1 := head, head.Next

    for next1 != nil {
        if next1.Next == nil {
            next0.Next = headTmp
            next1 = nil
        } else if next1.Next.Next == nil {
            next0.Next = next1.Next
            next1.Next = nil
            next0.Next.Next = headTmp
            next1 = nil
        } else {
            next0.Next = next1.Next
            next0 = next0.Next
            next1.Next = next0.Next
            next1 = next1.Next
        }
    }

    return head
}
