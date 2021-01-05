/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

// 从当前直接向后一直查找，找到和为0就终止，并返回下一个节点和true，否则返回nil, false
func removeFromCurr(head *ListNode) (*ListNode, bool) {
	if head == nil {
		return nil, false
	}
	var val int
	for head != nil {
        // 加起来
		val += head.Val
		if val == 0 {
			return head.Next, true
		}
		next = head.Next
	}

	return nil, false
}

func removeZeroSumSublists(head *ListNode) *ListNode {
	// 只是说要变成不存在字串为0的，不要求最短
	if head == nil {
		return head
	}
	next := head
	var pre *ListNode
	for next != nil {
		if n, ok := removeFromCurr(next); ok {
			if pre == nil {
                // 第一个节点就凑到了0
				head = n
				next = n
			} else {
                // 后续节点凑到了0
                pre.Next = n
				next = n
			}
		} else {
            // pre替换到next，next后移一个
			pre = next
			next = next.Next
		}
	}

	return head
}
