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
    ListNode* removeElements(ListNode* head, int val) 
    {
        
        ListNode* temp =head;
        ListNode* prev =NULL;
        
        while(temp!=NULL)
        {
            if(temp->val == val)
            {
                if(prev == NULL)
                {
                    ListNode* del = head;
                    head=head->next;
                    
                    delete del;
                    temp=head;
                }
                else
                {
                    ListNode* del =temp;
                    prev->next = temp ->next;
                    temp=temp->next;
                    delete del;
                    
                }
                
            }
            else
            {
                prev=temp;
                temp=temp->next;
            }
            //cout<<temp->val;
            
        }
        
        return head;
        
    }
};