// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};


class PeekingIterator : public Iterator {
    int num;
    // num是否被缓存
    bool cached;
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums),
                                               cached(false) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        // 取出缓存
        if (cached) {
            return num;   
        } else if (hasNext()){
            // 产生新的缓存
            cached = true;
            num = Iterator::next();
        }
        return num;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        // 取出缓存
	    if (cached) {
            cached = false;
        } else {
            num = Iterator::next();
        }
        return num;
	}

	bool hasNext() const {
        // 有缓存或者有下一个
	    return Iterator::hasNext() || cached;
	}
};
