
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 如果有一个空即完蛋
        if (headA == nullptr || headB == nullptr) return nullptr;
        // 先获得2个链表长度，再判断最后一个节点是否相同，再根据长度差得到交点
        ListNode*a = headA;
        ListNode*b = headB;
        int lenA = 0;
        int lenB = 0;
        while (a->next != nullptr) {
            lenA++;
            a = a->next;
        }
        while (b->next != nullptr) {
            lenB++;
            b = b->next;
        }
        // 尾结点一样即相交
        if (a == b) {
            // 存储长度差
            int t = 0;
            // a存储较短链表，b存储较长链表
            if (lenB > lenA) {
                a = headA;
                b = headB;
                t = lenB - lenA;
            } else {
                a = headB;
                b = headA;
                t = lenA - lenB;
            }
            // 长的往后动一下
            for (int i = 0; i < t; ++i) {
                b = b->next;
            }
            // 寻找交点
            while (a != b) {
                a = a->next;
                b = b->next;
            }
            return a;
        } else {
            return nullptr;
        }
    }
};