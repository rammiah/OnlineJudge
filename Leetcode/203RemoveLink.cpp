class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // 递归玩的6就是好
        if (head == nullptr) return nullptr;
        if (head->val != val) {
            head->next = removeElements(head->next);
            return head;
        } else {
            return removeElements(head->next);
        }
    }
};