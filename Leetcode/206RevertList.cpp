
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 我都要晕了
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)return nullptr;
        if (head->next == nullptr) return head;
        ListNode *pri = nullptr, *ths = nullptr, *next = nullptr;
        pri = nullptr;
        ths = head;
        next = head;
        while (next != nullptr)
        {
            next = ths->next;
            ths->next = pri;
            pri = ths;
        }
        return ths;
    }
};