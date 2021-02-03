/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
    head := list1
    for i := 1; i < a; i++ {
        head = head.Next
    }
    next := head.Next
    head.Next = list2

    for list2.Next != nil {
        list2 = list2.Next
    }
    for i := a; i <= b; i++ {
        next = next.Next
    }
    list2.Next = next

    return list1
}
