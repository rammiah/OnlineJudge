// 1e9 + 7
const mod = 1000000007

func kConcatenationMaxSum(arr []int, k int) int {
	// 情况有点多，但是还好
	// 首先算一下前置最大序列的和和后置最大序列的和，求一下整体的和
	// 左半边和（？）
	leftSum := 0
	// 右半边和（？）
	rightSum := 0
	rightTmp := 0
	// 整体和
	allSum := 0
	// 中间子数组和
	midTmp := 0
	midSum := 0
	n := len(arr)
	// 求和
	for i, num := range arr {
		allSum += num
		if allSum > leftSum {
			leftSum = allSum
		}
		rightTmp += arr[n-i-1]
		if rightTmp > rightSum {
			rightSum = rightTmp
		}
		midTmp += num
		if num > 0 {
			if midTmp > midSum {
				midSum = midTmp
			}
		} else if midTmp < 0 {
			midTmp = 0
		}
	}
	// n为1时确定是中间
	if k == 1 {
		return midSum
	} else {
		// 总数目大于等于2时
		// 整体和小于0，只能是左加右或者中间
		if allSum <= 0 {
			// 只能使用一部分求和
			if midSum > leftSum+rightSum {
				return midSum
			}
			return leftSum + rightSum
		} else {
			// 大于0的话就好办了，左+(k-2)*allSum+右
			sum := int64(leftSum+rightSum) + int64(k-2)*int64(allSum)
			return int(sum % mod)
		}
	}
}
