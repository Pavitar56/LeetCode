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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_map<ListNode*,bool> map;
        
        ListNode* temp1 = headA;
        
        while(temp1 != NULL)
        {
            map[temp1] = true;
            
            temp1 = temp1->next;
        }
        
        ListNode* temp2 = headB;
        
        while(temp2 != NULL)
        {
            if(map.count(temp2) > 0)
            {
                return temp2;
            }
            temp2 = temp2 -> next;
            
        }
        
        return NULL;
        
    }
};