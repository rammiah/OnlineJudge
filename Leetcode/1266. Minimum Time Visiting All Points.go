package leetcode

func distance(x0, y0, x1, y1 int) int {
	x := x0 - x1
	if x < 0 {
		x = -x
	}
	y := y0 - y1
	if y < 0 {
		y = -y
	}

	if x < y {
		return y
	}

	return x
}

func minTimeToVisitAllPoints(points [][]int) int {
	var res int
	x, y := points[0][0], points[0][1]
	for _, p := range points[1:] {
		res += distance(x, y, p[0], p[1])
		x, y = p[0], p[1]
	}

	return res
}
