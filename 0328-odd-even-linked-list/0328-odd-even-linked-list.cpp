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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* oddHead = NULL;
        ListNode* oddTail = NULL;
        
        ListNode* evenHead = NULL;
        ListNode* evenTail = NULL;
        
        ListNode* curr = head;
        int i=1;
        
        while(curr != NULL)
        {
            if(i%2 != 0)
            {
                if(oddHead == NULL)
                {
                    oddHead = curr;
                    oddTail = curr;
                }
                else
                {
                    oddTail->next = curr;
                    oddTail = curr;
                }
                
                
            }
            else
            {
                if(evenHead == NULL)
                {
                    evenHead = curr;
                    evenTail = curr;
                }
                else
                {
                    evenTail -> next = curr;
                    evenTail = curr;
                }
            }
            
            curr= curr->next;
            i++;
            
        }
        
        oddTail->next = evenHead;
        evenTail->next = NULL;
        return oddHead;
        
        
    }
};