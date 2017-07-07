class MyStack {
    queue<int>temp, in_out;
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        in_out.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while (in_out.size() > 1) {
            temp.push(in_out.front());
            in_out.pop();
        }
        int t = in_out.front();
        in_out.pop();
        while (!temp.empty()) {
            in_out.push(temp.front());
            temp.pop();
        }
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return in_out.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return in_out.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

