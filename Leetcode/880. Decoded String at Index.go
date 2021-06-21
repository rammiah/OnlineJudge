package leetcode

type indexer struct {
	str    string // string appent content
	sumLen int64  // length of tape
	lastC  string // optimize for K == 0
}

func decodeAtIndex(s string, k int) string {
	// arr contains all length after repeat
	index := make([]*indexer, 1, 200)
	var idx int
	index[idx] = &indexer{
		str:    "",
		sumLen: 0,
	}
	for _, c := range s {
		if c >= '2' && c <= '9' {
			cnt := int64(c - '0')
			index = append(index, &indexer{
				str:    "",
				sumLen: cnt * index[idx].sumLen,
				lastC:  index[idx].lastC,
			})
			idx++
		} else {
			index[idx].sumLen++
			index[idx].lastC = string(c)
			index[idx].str = index[idx].str + index[idx].lastC
		}
	}

	var K = int64(k)

	// reverse iterate
	for idx >= 0 {
		i := index[idx]
		K %= i.sumLen
		if K == 0 {
			// just great
			return i.lastC
		}
		if K > i.sumLen-int64(len(i.str)) {
			return string(i.str[K+int64(len(i.str))-i.sumLen-1])
		}
		idx--
	}

	return ""
}
