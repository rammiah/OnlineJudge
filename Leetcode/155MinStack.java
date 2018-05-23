public class MinStack {
    long min;
    Stack<Long>stack;
    /** initialize your data structure here. */
    public MinStack() {
        min = 0;
        stack = new Stack<>();
    }
    
    public void push(int x) {
        long t = x;
        if (stack.isEmpty()) {
            // 最小就是t
            min = t;
            // 压入0L
            stack.push(0L);
        } else {
            // 压入差值，真是佩服
            stack.push(t - min);
            if (t < min) {
                min = t;
            }
        }
    }
    
    public void pop() {
        // 这里就需要想到开始压入0L的原因了
        long t = stack.pop();
        if (t < 0) {
            min = min - t;
        }
    }
    
    public int top() {
        long t = stack.peek();
        if (t > 0) {
            return (int)(t + min);
        } else {
            return (int)(min);
        }
    }
    
    public int getMin() {
        return (int)min;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */