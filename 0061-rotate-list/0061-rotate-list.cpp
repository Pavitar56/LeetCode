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
    
    int Length(ListNode* head)
    {
        int count = 0;
        while(head != NULL)
        {
            count++;
            head = head -> next;
        }
        
        return count;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nNode = NULL;
        
        if(curr != NULL)
        {
            nNode = curr->next;
        }
        
        while(curr != NULL)
        {
            nNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nNode;
        }
        
        return prev;
        
        
    }
    
    
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(k==0 || head == NULL)
        {
            return head;
        }
        
        int len = Length(head);    
        k = k  - (k/len) * len;
        
        if(k==0)
        {
            return head;
        }
        head = reverse(head);
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nNode = NULL;
        
        if(curr != NULL)
        {
            nNode = curr->next;
        }
        
        for(int i=0;i<k;i++)
        {
            nNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nNode;
            
        }
        
        ListNode* newHead = prev;
        ListNode* newTail = head;
        
        prev = NULL;
        for(int i=0;i<(len - k);i++)
        {
            nNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nNode;
            
        }
        
        newTail->next = prev;
        
        return newHead;
    }
};