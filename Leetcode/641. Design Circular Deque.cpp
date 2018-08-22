class MyCircularDeque {
    int cap, size;
    int front, back;
    int *data;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cap = k;
        size = 0;
        front = 0;
        back = 0;
        data = new int[k];
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (size < cap) {
            front = (front - 1 + cap) % cap;
            data[front] = value;
            ++size;
            return true;
        }
        return false;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (size < cap) {
            data[back] = value;
            back = (back + 1) % cap;
            ++size;
            return true;
        }
        return false;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (size >= 1) {
            front = (front + 1) % cap;
            --size;
            return true;
        }
        return false;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (size >= 1) {
            back = (back - 1 + cap) % cap;
            --size;
            return true;
        }
        return false;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (size >= 1) {
            return data[front];
        }
        return -1;
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (size >= 1) {
            return data[(back - 1 + cap) % cap];
        }
        return -1;
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == cap;
    }

    ~MyCircularDeque() {
        delete[] data;
    }
};

/**
* Your MyCircularDeque object will be instantiated and called as such:
* MyCircularDeque obj = new MyCircularDeque(k);
* bool param_1 = obj.insertFront(value);
* bool param_2 = obj.insertLast(value);
* bool param_3 = obj.deleteFront();
* bool param_4 = obj.deleteLast();
* int param_5 = obj.getFront();
* int param_6 = obj.getRear();
* bool param_7 = obj.isEmpty();
* bool param_8 = obj.isFull();
*/