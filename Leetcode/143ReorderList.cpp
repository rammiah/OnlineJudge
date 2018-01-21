struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution_Mine {
private:
    void last(ListNode *node) {
        if (node->next->next == nullptr) return;
        ListNode *temp = node, *next = node->next;

        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        node->next = temp->next;
        temp->next = nullptr;
        temp = node->next;
        temp->next = next;
        first(next);
    }

    void first(ListNode *node) {
        if (node == nullptr || node->next == nullptr) return;
        last(node);
    }

public:
    void reorderList(ListNode* head) {
        first(head);
    }
};

// Best answer
class Solution_Bset {
public:
    void reorderList(ListNode* head) {
       if(!head || !head->next) return; 
        
        ListNode *slow=head, *fast=head; 
        
        while(fast->next&& fast->next->next){
            slow=slow->next;
            fast=fast->next->next; 
        }
        
       ListNode *head2=slow->next; 
       slow->next=NULL; 
        
       head2= reverse(head2); 
        
        ListNode *curr=head; 
        
      while(curr->next){
          ListNode *tmp=curr->next; 
          curr->next=head2; 
          head2=head2->next;
          curr->next->next=tmp; 
          curr=tmp;   
      }
       curr->next=head2;  
        
    }
    
    ListNode *reverse(ListNode *head){
        if(!head || !head->next) return head; 
        
        ListNode *prev=head, *cur=prev->next, *next=cur->next; 
        
        for( ; cur ; prev=cur, cur=next, next=cur? cur->next:NULL) cur->next=prev; 
        
        head->next=NULL;
        
        return prev; 
        
    }  
};