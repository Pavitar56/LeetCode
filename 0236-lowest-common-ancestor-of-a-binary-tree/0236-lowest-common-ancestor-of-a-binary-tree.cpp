/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        
        if(root == NULL)
        {
            return NULL;
        }
        
        if(root == p || root == q)
        {
            return root;
        }
        
        
        TreeNode* lcaLeft = lowestCommonAncestor(root->left,p,q);
        TreeNode* lcaRight = lowestCommonAncestor(root->right,p,q);
        
        if(lcaLeft !=NULL && lcaRight !=NULL)
        {
            return root;
        }
        
        if(lcaLeft !=NULL)
        {
            return lcaLeft;
        }
        
        return lcaRight;
        
        
    }
};