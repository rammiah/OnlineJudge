type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func traverseTree(root *TreeNode, eval func(int)) {
	if root == nil {
		return
	} else if root.Left == nil && root.Right == nil {
		// 闭包了解一下
		eval(root.Val)
		return
	}
	traverseTree(root.Left, eval)
	traverseTree(root.Right, eval)
}

func leafSimilar(root1 *TreeNode, root2 *TreeNode) bool {
	// 判断叶子节点顺寻是否相同，有点意思哦
	// 最简单的方式，获取两个树的节点序列，直接比对即可
	var lst1, lst2 []int
	traverseTree(root1, func(val int) {
		lst1 = append(lst1, val)
	})
	traverseTree(root2, func(val int) {
		lst2 = append(lst2, val)
	})
	if len(lst1) != len(lst2) {
		return false
	}
	for i, val := range lst1 {
		if val != lst2[i] {
			return false
		}
	}
	return true
}
