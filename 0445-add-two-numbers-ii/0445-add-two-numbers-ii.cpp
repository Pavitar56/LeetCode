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
    
//     void convert_LL_Num(ListNode* head,vector<int> &num)
//     {
//         ListNode* temp=head;
        
//         while(temp!=NULL)
//         {
//             num.push_back(temp->val);
//             temp=temp->next;
//         }
        
//     }
    
//     ListNode* reverse(ListNode* head)
//     {
        
//         if(head == NULL || head->next == NULL)
//         {
//             return head;
//         }
        
//         ListNode* prev=NULL;
//         ListNode* temp=head;
        
//         while(temp!=NULL)
//         {
//             ListNode* nxt = temp->next;
            
//             temp->next = prev;
//             prev=temp;
//             temp=nxt;
            
//         }
        
//         return prev;
        
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
//     {
//         vector<int> num1;
//         vector<int> num2;
        
//         convert_LL_Num(l1,num1);
//         convert_LL_Num(l2,num2);
        
//         std::reverse(num1.begin(),num1.end());
//         std::reverse(num2.begin(),num2.end());
        
//         int i=0,j=0;
//         int carry=0;
//         int sum=0;
        
//         ListNode* head = NULL;
//         ListNode* tail = NULL;
        
        
//         while(i<num1.size() && j<num2.size())
//         {
//             sum = carry + num1[i] + num2[i];
            
//             carry = sum/10;
            
//             if(head==NULL)
//             {
//                 head=new ListNode(sum%10);
//                 tail=head;
//             }
//             else
//             {
//                 tail->next = new ListNode(sum%10);
//                 tail = tail->next;
//             }
         
//             i++;
//             j++;
//         }
        
//         while(i<num1.size())
//         {
//             sum = carry + num1[i];
            
//             carry = sum/10;
            
//             if(head==NULL)
//             {
//                 head=new ListNode(sum%10);
//                 tail=head;
//             }
//             else
//             {
//                 tail->next = new ListNode(sum%10);
//                 tail = tail->next;
//             }
//             i++;
//         }
        
//         while(j<num2.size())
//         {
//             sum = carry + num2[j];
            
//             carry = sum/10;
            
//             if(head==NULL)
//             {
//                 head=new ListNode(sum%10);
//                 tail=head;
//             }
//             else
//             {
//                 tail->next = new ListNode(sum%10);
//                 tail = tail->next;
//             }
//             j++;
//         }
//         if(carry!=0)
//         {
//             if(head==NULL)
//             {
//                 head=new ListNode(carry);
//                 tail=head;
//             }
//             else
//             {
//                 tail->next = new ListNode(carry);
//                 tail = tail->next;
//             }
//         }
        
//         ListNode* newHead = reverse(head);
//         return newHead;
//     }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
            stack<int> s1, s2;
            ListNode* head = NULL;  // new head of result LL
            int carry = 0;

            // insert elements of both linked lists into stacks
            ListNode* h1 = l1;
            while(h1) 
            {
                s1.push(h1->val);
                h1 = h1->next;
            }

            ListNode* h2 = l2;
            while(h2) 
            {
                s2.push(h2->val);
                h2 = h2->next;
            }

            while(!s1.empty() || !s2.empty())
            {
                int sum = (s1.empty() ? 0 : s1.top()) + (s2.empty() ? 0 : s2.top()) + carry;
                carry = sum>=10 ? 1 : 0;
                ListNode * temp = new ListNode(sum%10);

                if(head==NULL)
                    head = temp;
                else
                {
                    temp->next = head;
                    head = temp;
                }

                if(!s1.empty()) s1.pop();
                if(!s2.empty()) s2.pop();

            }
            // 9->9 + 9->9 = 1->9->8 type of case
            if(carry == 1)
            {
                ListNode * temp = new ListNode(1);
                temp->next = head;
                head = temp;
            }
        
        return head;

    }
};