class MyCircularQueue {
    int front, back;
    int size, cap;
    int *data = nullptr;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = 0;
        cap = k;
        front = back = 0;
        data = new int[k];
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (size < cap) {
            data[back] = value;
            back = (back + 1) % cap;
            ++size;
            return true;
        }
        return false;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (size >= 1) {
            front = (front + 1) % cap;
            --size;
            return true;
        }
        return false;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (size >= 1) {
            return data[front];
        }
        return -1;
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (size >= 1) {
            return data[(back - 1 + cap) % cap];
        }
        return -1;

    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == cap;
    }

    ~MyCircularQueue() {
        delete[] data;
    }
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue obj = new MyCircularQueue(k);
* bool param_1 = obj.enQueue(value);
* bool param_2 = obj.deQueue();
* int param_3 = obj.Front();
* int param_4 = obj.Rear();
* bool param_5 = obj.isEmpty();
* bool param_6 = obj.isFull();
*/