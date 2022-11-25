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
    bool hasCycle(ListNode *head) {
        
        
        unordered_map<ListNode*,bool> map;
        
        ListNode* temp = head;
        
        while(temp!=NULL)
        {
            if(map.count(temp)>0)
            {
                return true;
            }
            map[temp] = true;
            
            temp = temp->next;
        }
        
        return false;
    }
};