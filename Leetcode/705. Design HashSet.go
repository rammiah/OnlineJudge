
type node struct {
    Key  int
    Next *node
}
type MyHashSet struct {
    table    []*node
    size     int
    capacity int
}

func hashKey(val int) int {
    // 如何计算hash key
    return val * 120932
}

/** Initialize your data structure here. */
func Constructor() MyHashSet {
    initCap := 10000
    return MyHashSet{
        table:    make([]*node, initCap),
        size:     0,
        capacity: initCap,
    }
}

func (this *MyHashSet) Add(key int) {
    if this.Contains(key) {
        return
    }
    hash := hashKey(key) % this.capacity
    newNode := &node{
        Key:  key,
        Next: this.table[hash],
    }
    this.table[hash] = newNode
    // 计算是否超出cap
    this.size++
    if float32(this.size)/float32(this.capacity) >= 0.8 {
        // TODO: 扩容
    }
}

func (this *MyHashSet) Remove(key int) {
    hash := hashKey(key) % this.capacity
    n := this.table[hash]
    if n != nil {
        if n.Key == key {
            this.table[hash] = n.Next
        } else {
            pre := n
            n = n.Next
            for n != nil && n.Key != key {
                pre = pre.Next
                n = n.Next
            }
            if n != nil {
                pre.Next = n.Next
            }
        }
    }
}

/** Returns true if this set contains the specified element */
func (this *MyHashSet) Contains(key int) bool {
    hash := hashKey(key) % this.capacity
    n := this.table[hash]
    if n != nil {
        for n != nil && n.Key != key {
            //this.table[hash] = n.Next
            n = n.Next
        }
        return n != nil
    }
    return false
}



/**
 * Your MyHashSet object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Add(key);
 * obj.Remove(key);
 * param_3 := obj.Contains(key);
 */
