package leetcode

import "strings"

func getSmallestString(n int, k int) string {
	// a count , z count , x value
	var ac, zc, left int
	k -= n
	const BASE = 25
	zc = k / BASE
	if zc*BASE == k {
		left = 0
		ac = n - zc
	} else {
		left = k - zc*BASE
		ac = n - 1 - zc
	}

	var sb strings.Builder
	sb.WriteString(strings.Repeat("a", ac))
	if left != 0 {
		sb.WriteByte(byte(left + 'a'))
	}
	sb.WriteString(strings.Repeat("z", zc))

	return sb.String()
}
