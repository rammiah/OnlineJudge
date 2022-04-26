func getDescentPeriods(prices []int) int64 {
	sum := int64(1)
	N := len(prices)
	cnt := int64(1)
	for i := 1; i < N; i++ {
		if prices[i] != prices[i-1]-1 {
			cnt = 1
		} else {
			cnt++
		}
        sum += cnt
	}
	return sum
}
