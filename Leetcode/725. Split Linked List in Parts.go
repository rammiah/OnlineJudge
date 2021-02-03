/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func splitListToParts(root *ListNode, k int) []*ListNode {
    // 简单的数学计算吧
    nodes := make([]*ListNode, 0)

    // 取得所有结点
    for root != nil {
        nodes = append(nodes, root)
        root = root.Next
    }
    n := len(nodes)
    // avg > 0 一定有结点是两个或者以上的
    avg := n / k
    more := n - k * avg
    // 前more个是avg+1个，后面是avg个
    result := make([]*ListNode, k)
    if avg == 0 {
        for i := 0; i < more; i++ {
            result[i] = nodes[i]
            nodes[i].Next = nil
        }
    } else {
        idx := 0
        for i := range result {
            result[i] = nodes[idx]
            if i < more {
                nodes[idx+avg].Next = nil
                idx += avg + 1
            } else {
                nodes[idx+avg-1].Next = nil
                idx += avg
            }
        }
    }

    return result
}
