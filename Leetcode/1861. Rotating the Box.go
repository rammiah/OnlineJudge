package leetcode

func rotateTheBox(box [][]byte) [][]byte {
	M := len(box)
	N := len(box[0])

	result := make([][]byte, 0, N)
	for i := 0; i < N; i++ {
		result = append(result, make([]byte, M))
	}
	// '.': empty, '#': stone, '*': obstacle

	for i := 0; i < M; i++ {
		COL := M - 1 - i
		idx := N - 1
		for j := N - 1; j >= 0; j-- {
			switch box[i][j] {
			case '#':
				result[idx][COL] = '#'
				idx--
			case '*':
				for idx > j {
					result[idx][COL] = '.'
					idx--
				}
				result[idx][COL] = '*'
				idx--
			}
		}
		for idx >= 0 {
			result[idx][COL] = '.'
			idx--
		}
	}

	return result
}
