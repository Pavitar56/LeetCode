/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node)
    {
        
//         ListNode* temp = node->next;
//         ListNode* prev = node;
        
        
//         while(temp->next != NULL)
//         {
//             int data = temp->val;
            
//             temp->val = prev->val;
//             prev->val = data;
            
//             temp=temp->next;
//             prev=prev->next;
            
//         }
        
//         int data = temp->val;
            
//         temp->val = prev->val;
//         prev->val = data;
        
//         delete temp;
//         prev->next = nullptr;
        
        //ListNode* nodeNext = node->next;
        
        node->val = node->next->val;
        
        node->next = node->next->next;
        
        
        
    }
};