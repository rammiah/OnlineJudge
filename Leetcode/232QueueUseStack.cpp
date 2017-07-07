class MyQueue {
public:
	// I am angry with the stack's pop functio in c++,very not handy
    stack<int>temp, in_out;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in_out.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!temp.empty()) {
            int t = temp.top();
            temp.pop();
            return t;
        } else {
            while (!in_out.empty()) {
                temp.push(in_out.top());
                in_out.pop();
            }
            int t = temp.top();
            temp.pop();
            return t;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if (!temp.empty()) {
             return temp.top();
        } else {
            while (!in_out.empty()) {
                temp.push(in_out.top());
                in_out.pop();
            }
            return temp.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return temp.empty() && in_out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

