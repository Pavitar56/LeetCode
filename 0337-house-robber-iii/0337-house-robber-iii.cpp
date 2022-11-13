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
    
    int helper(TreeNode* root, unordered_map<TreeNode*,int> &dp)
    {
        if(root == NULL)
        {
            return 0;
            
        }
        
        
        if(dp.count(root) > 0)
        {
            return dp[root];
        }
        
        
        int excluding_root = helper(root->left,dp) + helper(root->right,dp);
        
        int including_root = root->val;
        
        if(root->left != NULL)
        {
            including_root += helper(root->left->left,dp) + helper(root->left->right,dp); 
            
        }
        
        if(root->right != NULL)
        {
            including_root += helper(root->right->left,dp) + helper(root->right->right,dp);
        }
        
        int ans;
        
        ans = max(excluding_root,including_root);
        
        dp[root] = ans;
        
        return ans;
        
    
    }
    
public:
    int rob(TreeNode* root) {
        
        unordered_map<TreeNode*,int> dp;
        
        return helper(root,dp);
        
        
    }
};