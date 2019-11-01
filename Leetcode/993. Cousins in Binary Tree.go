/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func getParentInfo(root *TreeNode, val, lev int) (*TreeNode, int) {
    // 这棵树不是搜索树，只能遍历了
    if root == nil {
        return nil, -1
    }
    if root.Left != nil && root.Left.Val == val || root.Right != nil && root.Right.Val == val {
        return root, lev
    }
    resNode, resLev := getParentInfo(root.Left, val, lev+1)
    if resNode != nil {
        return resNode, resLev
    }
    resNode, resLev = getParentInfo(root.Right, val, lev+1)
    if resNode != nil {
        return resNode, resLev
    }
    return nil, -1
}

func isCousins(root *TreeNode, x int, y int) bool {
    xNode, xLev := getParentInfo(root, x, 0)
    yNode, yLev := getParentInfo(root, y, 0)
    return xNode != yNode && xLev == yLev
}
