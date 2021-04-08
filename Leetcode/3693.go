package leetcode

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
    if head == nil || head.Next == nil {
        return true
    }

    fast, slow := head, head
    var next *ListNode
    for fast != nil && fast.Next != nil {
        // just move next
        fast = fast.Next.Next
        tmp := slow
        slow = slow.Next
        tmp.Next = next
        next = tmp
    }
    // odd count nodes
    if fast != nil {
        slow = slow.Next
    }
    for next != nil {
        if next.Val != slow.Val {
            return false
        }
        next = next.Next
        slow = slow.Next
    }

    return true
}
