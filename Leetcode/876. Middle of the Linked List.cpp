/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode* head) {
        vector<int> nums;
        ListNode *temp = head;
        int len = 0;
        while (temp != nullptr) {
            ++len;
            temp = temp->next;
        }
        // 计算需要向后移动多少个
        // 3移1，2移1，4移2
        len /= 2;
        temp = head;
        while (len) {
            temp = temp->next;
            --len;
        }
        return temp;
    }
};