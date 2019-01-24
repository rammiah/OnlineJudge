/*
// Definition for a Node.
class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node() {}

    Node(int _val, Node *_prev, Node *_next, Node *_child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/

class Solution {
public:
    Node *flatten(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node *next = flatten(head->next);
        Node *child = flatten(head->child);
        if (child != nullptr) {
            if (next != nullptr) {
                // 需要将next接到child最后面
                Node *end = child;
                while (end->next != nullptr) {
                    end = end->next;
                }
                end->next = next;
                next->prev = end;
            }
            head->child = nullptr;
            head->next = child;
            child->prev = head;
        }

        return head;
    }
};

