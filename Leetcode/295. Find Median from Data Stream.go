// 最大堆还是最小堆，还是传一个参数吧
type PriorityQueue struct {
	data []int
	big  bool
}

func NewPriorityQueue(big bool) *PriorityQueue {
	return &PriorityQueue{data: nil, big: big}
}

func (pq *PriorityQueue) Push(val int) {
	// 插入然后
	pq.data = append(pq.data, val)
	// 将数据向上推
	idx := len(pq.data) - 1
	for idx > 0 {
		// 此处一坑，parent的计算
		parent := (idx - 1) / 2
		// 自动大小堆
		if pq.data[parent] < pq.data[idx] == pq.big {
			pq.data[parent], pq.data[idx] = pq.data[idx], pq.data[parent]
			idx = parent
		} else {
			break
		}
	}
}

func (pq *PriorityQueue) Pop() int {
	val := pq.data[0]
	n := len(pq.data)
	pq.data[0] = pq.data[n-1]
	// 最后一个元素去掉
	pq.data = pq.data[:n-1]
	n--
	//n /= 2
	// 开始平衡
	idx := 0
	for idx < n {
		maxIdx := idx
		//oldIdx := idx
		left, right := idx*2+1, idx*2+2
		if left < n && pq.data[left] > pq.data[maxIdx] == pq.big {
			maxIdx = left
		}
		if right < n && pq.data[right] > pq.data[maxIdx] == pq.big {
			maxIdx = right
		}
		if maxIdx != idx {
			// 交换数据
			pq.data[idx], pq.data[maxIdx] = pq.data[maxIdx], pq.data[idx]
			idx = maxIdx
		} else {
			break
		}
	}

	return val
}

func (pq *PriorityQueue) Size() int {
	return len(pq.data)
}

func (pq *PriorityQueue) Top() int {
	return pq.data[0]
}

func (pq *PriorityQueue) Empty() bool {
	return len(pq.data) == 0
}

type MedianFinder struct {
	// golang没有优先队列
	left, right *PriorityQueue
}

/** initialize your data structure here. */
func Constructor() MedianFinder {
	return MedianFinder{
		left:  NewPriorityQueue(true),
		right: NewPriorityQueue(false),
	}
}

func (this *MedianFinder) AddNum(num int) {
	if this.left.Empty() {
		// 直接给left吧
		this.left.Push(num)
		return
	} else if this.right.Empty() {
		if num < this.left.Top() {
			this.right.Push(this.left.Pop())
			this.left.Push(num)
		} else {
			this.right.Push(num)
		}
		return
	}
	// 两者都不是空的
	left := this.left.Top()
	right := this.right.Top()
	if num < left {
		if this.left.Size() > this.right.Size() {
			this.right.Push(this.left.Pop())
		}
		this.left.Push(num)
	} else if num > right {
		// 放右边
		if this.right.Size() == this.left.Size() {
			this.left.Push(this.right.Pop())
		}
		this.right.Push(num)
	} else {
		// 比大小哈哈
		if this.left.Size() == this.right.Size() {
			this.left.Push(num)
		} else {
			this.right.Push(num)
		}
	}
}

func (this *MedianFinder) FindMedian() float64 {
	if this.left.Size() == this.right.Size() {
		return (float64(this.left.Top()) + float64(this.right.Top())) / 2
	} else {
		return float64(this.left.Top())
	}
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddNum(num);
 * param_2 := obj.FindMedian();
 */
