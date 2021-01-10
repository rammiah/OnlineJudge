package leetcode

// 递归估计要爆炸
// 看了别人的dfs居然可以，低估了go的栈了
func countSubTrees(n int, edges [][]int, labels string) []int {
	// 建立父结点到子节点的映射
	result := make([]int, n)
	childs := make([][]int, n)
	// 记录结点的深度，以便遇见结点的时候知道谁是父结点
	// 可能子节点先出现
	depth := make([]int, n)
	depth[0] = n
	orders := make([]int, 0, n)
	orders = append(orders, 0)
	for _, e := range edges {
		// 如果子节点和父结点都没出现过直接panic
		if depth[e[0]] > depth[e[1]] {
			childs[e[0]] = append(childs[e[0]], e[1])
			orders = append(orders, e[1])
			depth[e[1]] = depth[e[0]] - 1
		} else if depth[e[1]] > depth[e[0]] {
			childs[e[1]] = append(childs[e[1]], e[0])
			orders = append(orders, e[0])
			depth[e[0]] = depth[e[1]] - 1
		} else {
			panic("no lead")
		}
	}
	// revese 倒序
	for i := 0; i < n/2; i++ {
		orders[i], orders[n-i-1] = orders[n-i-1], orders[i]
	}
	// 一个结点最多只能是一个结点的子节点
	// 他的数据计算出来之后就可以直接给到别的结点了
	nums := make([][]int, n)
	// 从n-1开始向前遍历是否可以保证
	for _, n := range orders {
		// map->slice 时间降了近200ms, 可见go的map确实有些慢了
		var m []int
		label := int(labels[n] - 'a')
		if len(childs[n]) == 0 {
			m = make([]int, 26)
			m[label] = 1
		} else {
			// 取得子树的map并将值加到目前的结点中去
			// 遍历过于耗时，考虑如何优化掉
			// 子节点有的直接使用
			m = nums[childs[n][0]]
			m[labels[n]]++
			if len(childs[n]) > 1 {
				for _, child := range childs[n][1:] {
					for b, c := range nums[child] {
						m[b] += c
					}
				}
			}
		}
		result[n] = m[label]
		nums[n] = m
	}

	return result
}
