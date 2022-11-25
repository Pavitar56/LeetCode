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
    ListNode *detectCycle(ListNode *head) 
    {
        
        unordered_map<ListNode*,int> map;
        
        ListNode* curr = head;
        int idx = 0;
        while(curr != NULL)
        {
            if(map.count(curr) > 0)
            {
                return curr;
            }
            
            
            map[curr] = idx;
            idx++;
            curr = curr->next;
        }
        
        return NULL;
        
        
    }
};