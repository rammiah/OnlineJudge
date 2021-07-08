import (
	"sort"
)

func maximumElementAfterDecrementingAndRearranging(arr []int) int {
	sort.Sort(sort.IntSlice(arr))

	arr[0] = 1
	N := len(arr)
	for i := 1; i < N; i++ {
		if arr[i]-arr[i-1] > 1 {
			arr[i] = arr[i-1] + 1
		}
	}

	return arr[N-1]
}
