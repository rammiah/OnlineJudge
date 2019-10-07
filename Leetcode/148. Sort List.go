type ListNode struct {
	Val  int
	Next *ListNode
}

// 使用归并排序即可
func mergeList(lst1, lst2 *ListNode) *ListNode {
	if lst1 == nil {
		return lst2
	} else if lst2 == nil {
		return lst1
	}
	var head, node *ListNode
	if lst1.Val < lst2.Val {
		head = lst1
		lst1 = lst1.Next
	} else {
		head = lst2
		lst2 = lst2.Next
	}
	node = head
	for lst1 != nil && lst2 != nil {
		if lst1.Val < lst2.Val {
			node.Next = lst1
			lst1 = lst1.Next
		} else {
			node.Next = lst2
			lst2 = lst2.Next
		}
		node = node.Next
	}
	// 拼接剩余串
	if lst1 != nil {
		node.Next = lst1
	}
	if lst2 != nil {
		node.Next = lst2
	}
	return head
}

func sortList(head *ListNode) *ListNode {
	// 首先假设这个函数可以排序
	if head == nil {
		return nil
	} else if head.Next == nil {
		return head
	}
	// 划分比较复杂，注意不要使递归陷入死循环
	lst1 := head
	lst2 := head.Next
	for lst2 != nil {
		// lst2后移两个
		lst2 = lst2.Next
		if lst2 == nil {
			break
		}
		lst2 = lst2.Next
		// lst1后移一个
		lst1 = lst1.Next
	}
	lst2 = lst1.Next
	lst1.Next = nil
	// 归并排序
	return mergeList(sortList(head), sortList(lst2))
}
