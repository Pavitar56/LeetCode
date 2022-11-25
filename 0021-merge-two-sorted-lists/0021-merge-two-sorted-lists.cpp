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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(list1 != NULL && list2 != NULL)
        {
            int val1 = list1->val;
            int val2 = list2->val;
            
            if(val1 < val2)
            {
                if(head == NULL)
                {
                    head = new ListNode(val1);
                    tail = head;
                }
                else
                {
                    ListNode* newNode =  new ListNode(val1);
                    tail->next = newNode;
                    tail = newNode;
                }
                list1 = list1 ->next;
                
            }
            else
            {
                if(head == NULL)
                {
                    head = new ListNode(val2);
                    tail = head;
                }
                else
                {
                    ListNode* newNode =  new ListNode(val2);
                    tail->next = newNode;
                    tail = newNode;
                }
                list2 = list2->next;
                
            }
             
        }
        
        if(list1 != NULL)
        {
            if(tail != NULL)
                tail->next = list1;
            else
                head = list1; 
        }
        
        if(list2!=NULL)
        {
            if(tail != NULL)
                tail->next = list2;
            else
                head =list2;
        }
        
        return head;
    }
};