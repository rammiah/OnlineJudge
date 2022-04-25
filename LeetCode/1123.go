func helper(root *TreeNode) (*TreeNode, int) {
	if root == nil {
		return nil, 0
	}
	l, ld := helper(root.Left)
	r, rd := helper(root.Right)
	if ld == rd {
		return root, rd + 1
	} else if ld > rd {
		return l, ld + 1
	} else {
		return r, rd + 1
	}
}

func lcaDeepestLeaves(root *TreeNode) *TreeNode {
	n, _ := helper(root)

	return n
}
