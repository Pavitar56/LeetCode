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
    
   int helper(TreeNode* root,int maxVal,int minVal)
    {
        if(!root)
        {
            return abs(maxVal-minVal);
        }

        maxVal=max(root->val,maxVal);
        minVal=min(root->val,minVal);

        int left=helper(root->left,maxVal,minVal);
        int right=helper(root->right,maxVal,minVal);
       
        return max(left,right);
    }


    int maxAncestorDiff(TreeNode* root)
    {
        if(!root)
            return 0;

        return helper(root,root->val,root->val);
    }
};