/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        if(root == nullptr)
        {
            return {};
        }
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        
        vector<int> odd;
        vector<int> even;
        int level = 1;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr==nullptr)
            {
                if(level%2 != 0)
                {
                    ans.push_back(odd);
                    odd.clear();
                }
                else
                {
                    reverse(even.begin(),even.end());
                    ans.push_back(even);
                    even.clear();
                }
                
                if(q.empty())
                {
                    break;
                }
                
                q.push(nullptr);
                level++;
                continue;
            }
            
            
            if(level%2 != 0)
            {
                 odd.push_back(curr->val);
            }
            else
            {
                even.push_back(curr->val);
            }
            
            
            if(curr->left!=nullptr)
            {
   
                q.push(curr->left);
            }
                
            
            if(curr->right!=nullptr)
            {
               
                q.push(curr->right);
            }   
               
        }
        
        return ans;
        
    }
};