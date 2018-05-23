class MyCalendar {
private:
    // 结点定义
    struct Node {
        int start;
        int end;
        Node *left = nullptr, *right = nullptr;
        Node(int s, int e):start(s), end(e){}
        Node():start(0), end(0){}
    };
    // 二叉树插入
    bool insert(Node *&node, int start, int end) {
        if (node == nullptr) {
            node = new Node(start, end);
            return true;
        } else {
            if (start >= node->end) {
                return insert(node->right, start, end);
            } else if (end <= node->start) {
                return insert(node->left, start, end);
            }
            return false;
        }
    }
    Node *node = nullptr;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        return insert(node, start, end);
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */