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
    
    int mod = 1000000007;
    long long int ans = 0;
    long long int helper(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        long long int leftSum = helper(root->left);
        long long int rightSum = helper(root->right);
         
        return root->val + leftSum + rightSum;
        
    }
    long long int solve(TreeNode* root,long long int sum)
    {
       if(root == NULL)
       {
           return 0;
       }
        
        long long int leftSum = solve(root->left,sum);
        long long int rightSum = solve(root->right,sum);
        
        long long int curSum = root->val + leftSum + rightSum;
        
        long long int SubSum = sum - curSum;
        
        ans=max(ans,(curSum * SubSum));
        
        return curSum;
        
        
    }
    int maxProduct(TreeNode* root) 
    {
        long long int totalSum = helper(root);
        
        solve(root,totalSum);
        
        return ans%mod;
    }
};