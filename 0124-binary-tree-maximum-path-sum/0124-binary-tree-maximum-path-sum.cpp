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
    int ans=INT_MIN;
    int solve(TreeNode*root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int l=solve(root->left);
        int r=solve(root->right);

        int temp=max(root->val,max(root->val+l,root->val+r));
        //cout<<root->val<<" "<<temp<<endl;
        ans=max(ans,max(temp,root->val+l+r));
        return temp;
    }
    public:
    int maxPathSum(TreeNode* root) 
    {
        int temp=solve(root);
        return ans;
    }
};