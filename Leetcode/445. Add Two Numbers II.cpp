/**
 * Definition for singly-linked list.
 */
#include <deque>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
private:
    int nums1[1000], nums2[1000];
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ll1 = l1, *ll2 = l2;
        int idx1 = 0, idx2 = 0;
        while (ll1 != nullptr) {
            nums1[idx1++] = ll1->val;
            ll1 = ll1->next;
        }
        while (ll2 != nullptr) {
            nums2[idx2++] = ll2->val;
            ll2 = ll2->next;
        }
        --idx1;
        --idx2;
        ListNode *node = nullptr, *last;
        int carry = 0;
        while (idx1 >= 0 && idx2 >= 0) {
            int sum = carry + nums1[idx1--] + nums2[idx2--];
            last = node;
            carry = sum / 10;
            sum %= 10;
            node = new ListNode(sum);
            node->next = last;
        }
        while (idx1 >= 0) {
            int sum = carry + nums1[idx1--];
            carry = sum / 10;
            sum %= 10;
            last = node;
            node = new ListNode(sum);
            node->next = last;
        }
        while (idx2 >= 0) {
            int sum = carry + nums2[idx2--];
            carry = sum / 10;
            sum %= 10;
            last = node;
            node = new ListNode(sum);
            node->next = last;
        }
        if (carry > 0) {
            last = node;
            node = new ListNode(carry);
            node->next = last;
        }

        return node;
    }
};