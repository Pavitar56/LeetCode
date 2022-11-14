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
    
    void helper(TreeNode* root,vector<TreeNode*> &serialize)
    {
        
        if(root == NULL)
        {
            return;
        }
        
        helper(root->left,serialize);
        serialize.push_back(root);
        helper(root->right,serialize);
        
        return;
    }
    
    
    
    TreeNode* convertBST(TreeNode* root)
    {
        vector<TreeNode*> serialize;
        
        helper(root,serialize);
        
        
        int i = serialize.size() - 2;
        
        
        while(i>=0)
        {
            
            serialize[i]->val += serialize[i+1]->val;
            i--;
            
        }
        
        return root;
        
        
    }
};