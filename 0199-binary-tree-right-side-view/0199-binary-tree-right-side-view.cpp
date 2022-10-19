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
    
    //TC : O(N) where n is no of nodes
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root == NULL)
        {
            return {};
        }
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr == NULL)
            {
                if(q.empty())
                {
                    break;
                }
                else
                {
                    q.push(NULL);
                    continue;
                }
                
            }
            
            if(q.front() == NULL)    //after poping if null then it means i m on the last element of that level
            {
                ans.push_back(curr->val);
            }
            
            if(curr->left != NULL)
            {
                q.push(curr->left);
            }
            
            if(curr->right != NULL)
            {
                q.push(curr->right);
            }
            
        }
        
        return ans;
        
        
    }
};