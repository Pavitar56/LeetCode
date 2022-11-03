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
    void flatten(TreeNode* root) 
    {
        if(root == NULL)
        {
            return;
        }
        
        TreeNode* l = root->left;
        
        TreeNode* r = root->right;
        
        
        
        flatten(l);
        flatten(r);
        
        root->left = NULL;
        if(l != NULL)
            root->right = l;
        
        TreeNode* prev = NULL;
        TreeNode* curr = l;
        
        while(curr!=NULL)
        {
            prev=curr;
            curr=curr->right;
        }
        
        if(prev!=NULL)
        {
            prev->right = r;
        }
        
    }
};