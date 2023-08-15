/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1 = NULL;
        ListNode* tail1 = NULL;
        
        ListNode* head2 = NULL;
        ListNode* tail2 = NULL;
        
        while(head != NULL)
        {
            if(head->val < x)
            {
                if(head1 == NULL)
                {
                    head1 = new ListNode(head->val);
                    tail1 = head1;
                }
                else
                {
                    tail1->next = new ListNode(head->val);
                    tail1 = tail1->next;
                }
                
            }
            else
            {
                
                if(head2 == NULL)
                {
                    head2 = new ListNode(head->val);
                    tail2 = head2;
                }
                else
                {
                    tail2->next = new ListNode(head->val);
                    tail2 = tail2->next;
                }
                
            }
            head = head->next;
        }
       
        if(head1 != NULL && head2 != NULL)
        {
            tail1->next = head2;
            tail2->next = NULL;
            return head1;
        }
        else if(head1 == NULL)
        {
            return head2;
        }
        else
        {
            return head1;
        }
        
    }
    
};