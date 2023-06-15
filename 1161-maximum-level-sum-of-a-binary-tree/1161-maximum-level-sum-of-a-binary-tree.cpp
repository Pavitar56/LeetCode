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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int maxSum = INT_MIN;
        
        int currSum = 0;
        int lvl = 0;
        int ans = 0;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr == NULL)
            {
                lvl++;
                if(currSum > maxSum)
                {
                    maxSum = currSum;
                    ans = lvl;
                }
                currSum = 0;
                
                if(!q.empty())
                {
                    q.push(NULL);
                    
                }
                
                
            }
            else
            {
                currSum += curr->val; 
                
                if(curr -> left != NULL)
                    q.push(curr->left);
                
                if(curr->right != NULL)
                    q.push(curr->right);
                
            }
            
        }
        
        return ans;
    }
};