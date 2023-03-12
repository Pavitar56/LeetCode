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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        
        for(int i=0;i<lists.size();i++)
        {
            ListNode* curr = lists[i];
            while(curr != NULL)
            {
                pq.push({curr->val,curr});
                curr = curr->next;
                
                
            }
        }
        
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(!pq.empty())
        {
            
            
            if(head == NULL)
            {
                head = pq.top().second;
                tail = pq.top().second;
            }
            else
            {
                tail->next = pq.top().second;
                tail = pq.top().second;
            }
            
            pq.pop();
        }
        
        if(head != NULL)
        {
            tail->next = NULL;
        }
        
        return head;
    }
};