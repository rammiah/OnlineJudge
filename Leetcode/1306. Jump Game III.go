// package leetcode

func canReach(arr []int, start int) bool {
	N := len(arr)
	visited := make([]bool, N)
	ls := make([]int, N)
	ls[0] = start
	idx := 0
	cnt := 1
	for cnt > idx {
		v := ls[idx]
		if arr[v] == 0 {
			return true
		}
		visited[v] = true
		left, right := v-arr[v], v+arr[v]
		if left >= 0 && !visited[left] {
			ls[cnt] = left
			cnt++
		}
		if right < N && !visited[right] {
			ls[cnt] = right
			cnt++
		}
		idx++
	}

	return false
}
