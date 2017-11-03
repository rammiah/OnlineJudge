/*************************************************************************
	> File Name: 002AddTwoNumbers.cpp
	> Author: Yaning Wang, CS1607
	> Mail: wangyanign6166@gmail.com
	> School: HUST
	> Created Time: 2017年05月04日 星期四 14时58分53秒
 ************************************************************************/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) { }
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result, *temp, *l = nullptr;
        int left = 0;
        bool first = true;
        while (l1 != nullptr || l2 != nullptr || left != 0) {
            l = new ListNode(0);
            if (l1 != nullptr){
                l->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr){
                l->val += l2->val;
                l2 = l2->next;
            }
            l->val += left;
            left = l->val / 10;
            l->val = l->val % 10;
            if (first){
                result = temp  = l;
                first = false;
            }
            else{
                temp = temp->next = l;
                // temp;
            }
        }
        return result;
    }
};
